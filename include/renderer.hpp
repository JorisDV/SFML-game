#pragma once

#include <SFML/Graphics.hpp>
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"

class Renderer
{
public:
    Renderer(sf::RenderWindow &window);

    void draw(Knight &knight, World &world, Sensors &sensors, HUD &hud);

private:
    void drawKnight(Knight &knight);
    void drawWorld(World &world);
    void drawHUD(HUD &hud, Knight &knight, Sensors &sensors);

    sf::RenderWindow &window;
    sf::View view;
};
