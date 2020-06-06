#pragma once
#include <SFML/Graphics.hpp>

class Field
{
private:
	char sessionField[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
public:
	void newGame();
	char gameState();
};

