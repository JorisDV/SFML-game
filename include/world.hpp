#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Platform
{
public:
    Platform() : rect(Config::Platform::SIZE),
                 position({Config::Knight::INITIAL_POSITION.x, Config::Knight::INITIAL_POSITION.y + Config::Platform::OUTLINE_THICKNESS})
    {
        rect.setOrigin({Config::Platform::SIZE.x / 2, 0});
        rect.setPosition(position);
        rect.setFillColor(Config::Platform::FILL_COLOR);
        rect.setOutlineColor(Config::Platform::OUTLINE_COLOR);
        rect.setOutlineThickness(Config::Platform::OUTLINE_THICKNESS);
    }

    sf::RectangleShape rect;
    sf::Vector2f position;
};