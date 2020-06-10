#include "Game.h"


Game::Game() : m_window{new sf::RenderWindow (sf::VideoMode (800, 800), "Tic Tac Toe", sf::Style::Close)}
{
    m_window->setFramerateLimit(120);
}

Game::~Game()
{
    delete m_window;
}
void Game::play()
{
    backgroundTexture.loadFromFile("images/background.jpg");
    background.setTexture(backgroundTexture);
    Field* gameField = new Field;
    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        //Update input

        //Update state

        //Render
        m_window->clear();
        m_window->draw(background);
        m_window->display();
    }
}
