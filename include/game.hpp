#pragma once

#include <SFML/Graphics.hpp>
#include "physics.hpp"
#include "renderer.hpp"
#include "sensors.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"

class Game
{
public:
    Game();

    void start();
    void restart();

private:
    void checkGameOver(sf::RenderWindow &window, Knight &knight);

    sf::RenderWindow window;
    Renderer renderer;
    Knight knight;
    World world;
    Sensors sensors;
    Physics physics;
    HUD hud;
    sf::Clock clock;
};
