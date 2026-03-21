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
        window.clear();
        drawKnight(knight);
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