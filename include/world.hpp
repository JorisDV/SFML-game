#pragma once

#include <vector>
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

    std::vector<Platform> platforms;

private:
    void generate_platforms();
    void generate_platform();

    std::default_random_engine generator;
    std::uniform_real_distribution<float> x_distr;
};
