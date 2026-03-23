#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"

class Renderer
{
public:
    explicit Renderer(sf::RenderWindow &window) : window(window) {}

    void draw(Knight &knight, World &world, Sensors &sensors)
    {
        window.clear(Config::Window::BACKGROUND_COLOR);

        window.draw(knight.sprite);
        drawWorld(world);
        drawHUD(knight, sensors);

        window.display();
    }

private:
    void drawWorld(World &world)
    {
        for (Platform platform : world.platforms)
        {
            window.draw(platform.rect);
        }
    }

    void drawHUD(Knight &knight, Sensors &sensors)
    {
        if (knight.hasJustLanded)
            hud.arrow.reset(knight, sensors);

        if (knight.isOnGround)
        {
            hud.arrow.update(sensors.angle);
            window.draw(hud.arrow.line);
            window.draw(hud.arrow.triangle);
        }

        hud.progress_bar.update(sensors);
        window.draw(hud.progress_bar.background);
        window.draw(hud.progress_bar.fill);
    }

    sf::RenderWindow &window;
    HUD hud;
};