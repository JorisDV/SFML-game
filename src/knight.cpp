#include <SFML/Graphics.hpp>
#include "knight.hpp"
#include "config.hpp"

Knight::Knight() : textureOnGround(Config::Knight::SPRITESHEET, false, sf::IntRect({0, 0}, {16, 16})),
                   textureJumping(Config::Knight::SPRITESHEET, false, sf::IntRect({16, 0}, {16, 16})),
                   sprite(textureOnGround)
{
    sprite.setScale({static_cast<float>(Config::Knight::SIZE) / 16,
                     static_cast<float>(Config::Knight::SIZE) / 16});
    sprite.setOrigin({8.0f, 16.0f});
    sprite.setPosition(position);
}
