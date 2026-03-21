#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "renderer.hpp"

class Game
{
public:
    Game() : window(sf::VideoMode({Config::Window::WIDTH, Config::Window::HEIGHT}), Config::Window::TITLE),
             renderer(window)
    {
        window.setFramerateLimit(Config::Window::FRAMERATE_LIMIT);
    }

    void start()
    {
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            renderer.draw(knight);
        }
    }

private:
    sf::RenderWindow window;
    Renderer renderer;
    Knight knight;
};