#pragma once
#include <SFML/Graphics.hpp>

#include "Cell.h"

class Field
{
private:
	//Refs
	sf::RenderWindow& m_window;

	const sf::Vector2u m_field_size;
	char** m_values;
	Cell** m_grids;

	//Init
	void initGrids();

public:
	Field(sf::RenderWindow& window, const sf::Vector2u& field_size);
	~Field();

	//Func
	char checkFieldState();
	char getCellState(short cell);

	//Update
	void update(sf::Vector2f& mouse_pos);

	//Render
	void render(sf::RenderTarget& target);
};

