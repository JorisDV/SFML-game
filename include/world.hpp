#pragma once

#include <deque>
#include <random>
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

    void reset();
    void generatePlatforms();
    void removePlatforms(sf::View &view);

    std::deque<Platform> platforms;

private:
    std::default_random_engine generator;
    std::uniform_real_distribution<float> x_distr;
};
