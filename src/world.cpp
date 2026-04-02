#include <vector>
#include <random>
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

World::World() : generator(std::random_device{}()),
                 x_distr(Config::Platform::SIZE.x / 2 + Config::Platform::OUTLINE_THICKNESS,
                         Config::Window::WIDTH - (Config::Platform::SIZE.x / 2 + Config::Platform::OUTLINE_THICKNESS))

{
    platforms.reserve(Config::World::NR_OF_PLATFORMS);
    generate_platforms();
}

void World::generate_platforms()
{
    platforms.emplace_back(Config::Knight::INITIAL_POSITION);

    while (platforms.size() < Config::World::NR_OF_PLATFORMS)
    {
        generate_platform();
    }
}

void World::generate_platform()
{
    float prev_platform_y = platforms.back().position.y;

    float min_y = prev_platform_y - Config::Physics::MAX_JUMP_HEIGHT;
    float max_y = prev_platform_y - Config::World::MIN_PLATFORM_SPACING;

    float range = max_y - min_y;

    float mean = min_y + range * Config::World::PLATFORM_HEIGHT_BIAS;
    float stddev = range * Config::World::PLATFORM_HEIGHT_SPREAD;

    std::normal_distribution<float> y_dist(mean, stddev);

    float y_sample;
    do
    {
        y_sample = y_dist(generator);
    } while (y_sample < min_y || y_sample > max_y);

    platforms.emplace_back(Platform({x_distr(generator), y_sample}));
}

void World::reset()
{
    platforms.clear();
    generate_platforms();
}
