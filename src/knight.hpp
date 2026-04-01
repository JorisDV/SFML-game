#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Knight
{
public:
    Knight();

    sf::Vector2f position = Config::Knight::INITIAL_POSITION;
    sf::Vector2f velocity = {0.0f, 0.0f};
    float prev_position_y = Config::Knight::INITIAL_POSITION.y;
    bool isOnGround = true;
    bool hasJustLanded = false;
    bool hasJustJumped = false;

    sf::Texture textureOnGround;
    sf::Texture textureJumping;
    sf::Sprite sprite;
};