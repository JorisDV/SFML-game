#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Knight
{
public:
    Knight() : texture(Config::Knight::TEXTURE),
               sprite(texture)
    {
        sf::Vector2u texture_size = texture.getSize();
        sprite.setScale({static_cast<float>(Config::Knight::SIZE) / texture_size.x,
                         static_cast<float>(Config::Knight::SIZE) / texture_size.y});
        sprite.setOrigin({static_cast<float>(texture_size.x) / 2.0f,
                          static_cast<float>(texture_size.y)});
        sprite.setPosition(position);
    }

    sf::Vector2f position = Config::Knight::INITIAL_POSITION;
    sf::Vector2f velocity = {0.0f, 0.0f};
    bool isOnGround = true;

private:
    sf::Texture texture;

public:
    sf::Sprite sprite;
};