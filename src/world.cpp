#include <vector>
#include <SFML/Graphics.hpp>
#include "world.hpp"
#include "config.hpp"

Platform::Platform(sf::Vector2f position) : rect(Config::Platform::SIZE),
                                            position(position)
{
    rect.setOrigin({Config::Platform::SIZE.x / 2, -Config::Platform::OUTLINE_THICKNESS});
    rect.setPosition(position);
    rect.setFillColor(Config::Platform::FILL_COLOR);
    rect.setOutlineColor(Config::Platform::OUTLINE_COLOR);
    rect.setOutlineThickness(Config::Platform::OUTLINE_THICKNESS);
}

World::World() : platforms({Platform({Config::Knight::INITIAL_POSITION.x, Config::Knight::INITIAL_POSITION.y}),
                            Platform({200, 500}),
                            Platform({600, 300})}) {}