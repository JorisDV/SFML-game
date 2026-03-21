#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Game
{
public:
    Game() : m_window(sf::VideoMode({Config::Window::WIDTH, Config::Window::HEIGHT}), Config::Window::TITLE)
    {
        m_window.setFramerateLimit(Config::FRAMERATE_LIMIT);
    }

    void start()
    {

        sf::CircleShape triangle(64.0f);
        triangle.setPointCount(3);
        triangle.setOrigin(triangle.getGeometricCenter());
        triangle.setPosition({Config::Window::WIDTH / 2.0f, Config::Window::HEIGHT / 2.0f});
        triangle.setFillColor(sf::Color::Green);

        while (m_window.isOpen())
        {
            while (const std::optional event = m_window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    m_window.close();
            }

            triangle.rotate(sf::degrees(1));

            m_window.clear();
            m_window.draw(triangle);
            m_window.display();
        }
    }

private:
    sf::RenderWindow m_window;
};