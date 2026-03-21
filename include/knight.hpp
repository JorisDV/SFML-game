#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Knight
{
public:
    sf::Vector2f position{Config::Window::WIDTH / 2, Config::Window::HEIGHT * 0.9};
    sf::Vector2f velocity{0.0f, 0.0f};
};