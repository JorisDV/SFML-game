#pragma once

#include <SFML/Graphics.hpp>

class Platform
{
public:
    Platform(sf::Vector2f position);

    sf::RectangleShape rect;
    sf::Vector2f position;
};

class World
{
public:
    World();

    std::vector<Platform> platforms;
};
