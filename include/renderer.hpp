#pragma once

#include <SFML/Graphics.hpp>
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"

class Renderer
{
public:
    Renderer(sf::RenderWindow &window);

    void draw(Knight &knight, World &world, Sensors &sensors, HUD &hud, float fps);

private:
    void drawKnight(Knight &knight);
    void drawWorld(World &world);
    void drawHUD(HUD &hud, Knight &knight, Sensors &sensors);
    void drawFPS(float fps);

    sf::RenderWindow &window;
    sf::Font font;
    sf::Text fps_text;
};