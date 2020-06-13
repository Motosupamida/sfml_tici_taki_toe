#include "Game.h"

Game::Game() 
    : m_window{ new sf::RenderWindow(sf::VideoMode(900, 900), "Tic Tac Toe", sf::Style::Close) }
{
    m_window->setFramerateLimit(120);

    initTexture();

    m_background.setTexture(m_textures["BACKGROUND"]);
    m_background.setSize(static_cast<sf::Vector2f>(m_window->getSize()));
}

Game::~Game()
{
    delete m_window;
}

//Init
void Game::initTexture()
{
    m_textures["BACKGROUND"] = new sf::Texture();

    if (!m_textures["BACKGROUND"]->loadFromFile("images/background.jpg"))
        throw "ERROR::GameState::init_textures::PLAYER_SHEET - failed to load texture resources/textures/Player/Player_sheet.png";

}

void Game::play()
{
    const sf::Vector2u DEFAULT_SIZE{ 3, 3 };

    Field gameField { *m_window , DEFAULT_SIZE };

    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }

        sf::Vector2f mouse_pos_view = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));

        //Update input
        gameField.update(mouse_pos_view);

        //Update state

        //Render
        m_window->clear();
        m_window->draw(m_background);
        gameField.render(*m_window);
        m_window->display();
    }
}
