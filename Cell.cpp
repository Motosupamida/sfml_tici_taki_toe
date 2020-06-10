#include "Cell.h"

Cell::Cell()
	: m_state { States::IDLE }
{
}

Cell::Cell(const sf::Vector2f& size, const sf::Vector2f& pos, 
		   const sf::Color& color_idle,
		   const sf::Color& color_hover,
		   const sf::Color& color_active)
	: sf::RectangleShape { size },
	m_state{ States::IDLE },
	m_color_idle{ color_idle },
	m_color_hover{ color_hover },
	m_color_active{ color_active }
{
	setPosition(pos);
}

Cell::~Cell()
{
}

void Cell::setColors(const sf::Color& idle, const sf::Color& hover, const sf::Color& active)
{
	m_color_idle = idle;
	m_color_hover = hover;
	m_color_active = active;
}

void Cell::update(const sf::Vector2f& mouse_pos)
{
	if (m_state < States::ACTIVE_LEFT)
	{
		m_state = States::IDLE;

		if (getGlobalBounds().contains(mouse_pos))
		{
			m_state = States::HOVER;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				m_state = States::ACTIVE_LEFT;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				m_state = States::ACTIVE_RIGHT;
		}

		switch (m_state)
		{
		case States::IDLE:
			setFillColor(m_color_idle);
			break;
		case States::HOVER:
			setFillColor(m_color_hover);
			break;
		case States::ACTIVE_LEFT:
			setFillColor(m_color_active);
			break;
		case States::ACTIVE_RIGHT:
			setFillColor(sf::Color::Black);
			break;
		default:
			setFillColor(sf::Color::Red);
			break;
		}
	}
}