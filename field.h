#pragma once
#include <SFML/Graphics.hpp>

class Field
{
private:
	char sessionField[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
public:
	Field();
	~Field();
	char checkFieldState();
	char getCellState(short cell);
};

