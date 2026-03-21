#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "renderer.hpp"

class Game
{
public:
    Game() : m_window(sf::VideoMode({Config::Window::WIDTH, Config::Window::HEIGHT}), Config::Window::TITLE),
             m_renderer(m_window)
    {
        m_window.setFramerateLimit(Config::FRAMERATE_LIMIT);
    }

    void start()
    {
        while (m_window.isOpen())
        {
            while (const std::optional event = m_window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    m_window.close();
            }

            m_renderer.draw(m_knight);
        }
    }

private:
    sf::RenderWindow m_window;
    Renderer m_renderer;
    Knight m_knight;
};