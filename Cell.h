#pragma once

#include "SFML/Graphics.hpp"

class Cell :
	public sf::RectangleShape
{
public:
	enum class States { NONE = -1, IDLE = 0, HOVER, ACTIVE_LEFT, ACTIVE_RIGHT};

	Cell();
	Cell(const sf::Vector2f& size, const sf::Vector2f& pos,
		 const sf::Color& color_idle,
		 const sf::Color& color_hover,
		 const sf::Color& color_active);
	~Cell();

	//Modificators
	void setColors(const sf::Color& idle, const sf::Color& hover, const sf::Color& active);

	//Update
	void update(const sf::Vector2f& mouse_pos);
private:
	States m_state;

	//Colors
	sf::Color m_color_idle;
	sf::Color m_color_hover;
	sf::Color m_color_active;
};