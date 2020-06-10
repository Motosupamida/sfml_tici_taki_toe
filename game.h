#pragma once
#include <SFML/Graphics.hpp>

#include "Field.h"

class Game
{
private:
	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	sf::RenderWindow *m_window;
public: 
	Game();
	~Game();
	void play();
};

