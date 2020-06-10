#include "Field.h"

#include <cmath>

Field::Field(sf::RenderWindow& window, const sf::Vector2u& field_size)
	: m_window{ window },
	m_field_size{ field_size }
{
	m_values = new char*[field_size.y];
	for (size_t i = 0; i < field_size.y; i++)
		m_values[i] = new char[field_size.x];

	initGrids();
}

Field::~Field()
{
	for (size_t i = 0; i < m_field_size.y; i++)
		delete[] m_grids[i];
	delete[] m_grids;

	for (size_t i = 0; i < m_field_size.y; i++)
		delete[] m_values[i];
	delete[] m_values;
}

void Field::initGrids()
{
	m_grids = new Cell* [m_field_size.y];
	for (size_t i = 0; i < m_field_size.y; i++)
		m_grids[i] = new Cell[m_field_size.x];

	for (size_t i = 0; i < m_field_size.y; i++)
	{
		for (size_t j = 0; j < m_field_size.x; j++)
		{
			const unsigned int default_x = m_window.getSize().x / m_field_size.x;
			const unsigned int default_y = m_window.getSize().y / m_field_size.y;

			m_grids[i][j].setSize(sf::Vector2f(default_x, default_y));
			m_grids[i][j].setPosition(sf::Vector2f(default_x * j, default_y * i));
			m_grids[i][j].setOutlineColor(sf::Color::Green);
			m_grids[i][j].setOutlineThickness(0.5f);

			m_grids[i][j].setColors(sf::Color(105, 105, 105, 200), sf::Color(192, 192, 192, 255), sf::Color::Red);
		}
	}
}

//Update
void Field::update(sf::Vector2f& mouse_pos)
{
	for (size_t i = 0; i < m_field_size.y; i++)
	{
		for (size_t j = 0; j < m_field_size.x; j++)
		{
			m_grids[i][j].update(mouse_pos);
		}
	}
}

//Render
void Field::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < m_field_size.y; i++)
		for (size_t j = 0; j < m_field_size.x; j++)
			target.draw(m_grids[i][j]);
}

/*
char Field::checkFieldState()
{
	char winCh = 'x';
	for (short i = 0; i < 2; i++)
	{
		if (((sessionField[0] == winCh) && (sessionField[1] == winCh) && (sessionField[2] == winCh)) || ((sessionField[3] == winCh) && (sessionField[4] == winCh) && (sessionField[5] == winCh))
			|| ((sessionField[6] == winCh) && (sessionField[7] == winCh) && (sessionField[8] == winCh)) || ((sessionField[0] == winCh) && (sessionField[3] == winCh) && (sessionField[6] == winCh))
			|| ((sessionField[1] == winCh) && (sessionField[4] == winCh) && (sessionField[7] == winCh)) || ((sessionField[2] == winCh) && (sessionField[5] == winCh) && (sessionField[8] == winCh))
			|| ((sessionField[6] == winCh) && (sessionField[4] == winCh) && (sessionField[2] == winCh)) || ((sessionField[8] == winCh) && (sessionField[4] == winCh) && (sessionField[0] == winCh)))
		{
			return winCh;//winner char
		}
		winCh = '0';
	}
	for (short i = 0; i < 9; i++)
	{
		if (sessionField[i] == ' ')
			return 'n';//game continues
	}
	return 'd'; //standoff
}

char Field::getCellState(short cell)
{
	return sessionField[cell];
}
*/