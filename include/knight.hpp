#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Knight
{
public:
    Knight() : texture("assets/knight.png"),
               sprite(texture)
    {
        sf::Vector2u texture_size = texture.getSize();
        sprite.setScale({static_cast<float>(Config::Knight::SIZE) / texture_size.x,
                         static_cast<float>(Config::Knight::SIZE) / texture_size.y});
        sprite.setOrigin({static_cast<float>(texture_size.x) / 2.0f,
                          static_cast<float>(texture_size.y)});
        sprite.setPosition(position);
    }

    sf::Vector2f position{Config::Window::WIDTH / 2, Config::Window::HEIGHT * 0.9};
    sf::Vector2f velocity{0.0f, 0.0f};

    void setPosition(sf::Vector2f position)
    {
        sprite.setPosition(position);
    }

private:
    sf::Texture texture;

public:
    sf::Sprite sprite;
};