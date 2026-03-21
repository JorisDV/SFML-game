#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"

class Renderer
{
public:
    explicit Renderer(sf::RenderWindow &window) : window(window) {}

    void draw(Knight &knight)
    {
        window.clear(Config::Window::BACKGROUND_COLOR);
        drawKnight(knight);

        sf::RectangleShape platform(Config::Platform::SIZE);
        platform.setOrigin({Config::Platform::SIZE.x / 2, 0});
        platform.setPosition(knight.position);
        platform.setFillColor(Config::Platform::FILL_COLOR);
        platform.setOutlineColor(Config::Platform::OUTLINE_COLOR);
        platform.setOutlineThickness(Config::Platform::OUTLINE_THICKNESS);
        window.draw(platform);

        window.display();
    }

private:
    void drawKnight(Knight &knight)
    {
        knight.setPosition(knight.position);
        window.draw(knight.sprite);
    }

    sf::RenderWindow &window;
};