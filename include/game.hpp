#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "physics.hpp"
#include "renderer.hpp"
#include "sensors.hpp"
#include "knight.hpp"
#include "world.hpp"

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

            float dt = clock.restart().asSeconds();
            sensors.poll(dt);
            physics.calculateKnightPosition(knight, world, sensors, dt);
            renderer.draw(knight, world, sensors);
        }
    }

private:
    sf::RenderWindow window;
    Renderer renderer;
    Knight knight;
    World world;
    Sensors sensors;
    Physics physics;
    sf::Clock clock;
};