#pragma once

#include <map>
#include <SFML/Graphics.hpp>

#include "Field.h"

class Game
{
private:
	sf::RenderWindow* m_window;
	std::map<std::string, sf::Texture*> m_textures;

	sf::RectangleShape m_background;

	//Init
	void inline initTexture();

public: 
	Game();
	~Game();

	void play();
};

