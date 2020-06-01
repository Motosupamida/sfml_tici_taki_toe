#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "JOPA", sf::Style::Close );
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            shape.move(1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            shape.move(-1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            shape.move(0, 1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            shape.move(0, -1);
        //Update state

        //Render
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}