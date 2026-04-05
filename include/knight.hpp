#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Knight
{
public:
    Knight();

    sf::Vector2f position;
    sf::Vector2f velocity;
    float prev_position_y;
    float highest_y;
    bool isOnGround;
    bool hasJustLanded;
    bool hasJustJumped;

    sf::Texture textureOnGround;
    sf::Texture textureJumping;
    sf::Sprite sprite;
};
