//#include <SFML/Graphics.hpp>
#include "stdHeader.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe", sf::Style::Close );
    window.setFramerateLimit(120);
    sf::Sprite background;
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("images/background.jpg");
    background.setTexture(backgroundTexture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update input
        
        //Update state

        //Render
        window.clear();
        window.draw(background);
        window.display();
    }

    return 0;
}