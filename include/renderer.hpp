#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"

class Renderer
{
public:
    explicit Renderer(sf::RenderWindow &window) : window(window),
                                                  font(Config::HUD::FPSCounter::FONT),
                                                  fps_text(font)
    {
        fps_text.setCharacterSize(Config::HUD::FPSCounter::SIZE);
        fps_text.setString("FPS: 9999");
        fps_text.setOrigin({fps_text.getGlobalBounds().size.x, 0});
        fps_text.setPosition(Config::HUD::FPSCounter::POSITION);
        fps_text.setFillColor(Config::HUD::FPSCounter::FILL_COLOR);
    }

    void draw(Knight &knight, World &world, Sensors &sensors, HUD &hud, float fps)
    {
        window.clear(Config::Window::BACKGROUND_COLOR);

        window.draw(knight.sprite);
        drawWorld(world);
        drawHUD(hud, knight, sensors);
        drawFPS(fps);

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

    void drawHUD(HUD &hud, Knight &knight, Sensors &sensors)
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

    void drawFPS(float fps)
    {
        fps_text.setString("FPS: " + std::to_string((int)fps));
        window.draw(fps_text);
    }

    sf::RenderWindow &window;
    sf::Font font;
    sf::Text fps_text;
};