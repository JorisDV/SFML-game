#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Knight
{
public:
    Knight() : textureOnGround(Config::Knight::SPRITESHEET, false, sf::IntRect({0, 0}, {16, 16})),
               textureJumping(Config::Knight::SPRITESHEET, false, sf::IntRect({16, 0}, {16, 16})),
               sprite(textureOnGround)
    {
        sprite.setScale({static_cast<float>(Config::Knight::SIZE) / 16,
                         static_cast<float>(Config::Knight::SIZE) / 16});
        sprite.setOrigin({8.0f, 16.0f});
        sprite.setPosition(position);
    }

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