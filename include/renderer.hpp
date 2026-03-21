#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"

class Renderer
{
public:
    explicit Renderer(sf::RenderWindow &window) : m_window(window) {}

    void draw(Knight &knight)
    {
        m_window.clear();
        drawKnight(knight);
        m_window.display();
    }

private:
    void drawKnight(Knight &knight)
    {
        knight.setPosition(knight.position);
        m_window.draw(knight.sprite);
    }

    sf::RenderWindow &m_window;
};