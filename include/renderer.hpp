#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"

class Renderer
{
public:
    explicit Renderer(sf::RenderWindow &window) : window(window) {}

    void draw(Knight &knight, Sensors &sensors)
    {
        window.clear(Config::Window::BACKGROUND_COLOR);

        drawKnight(knight);
        drawPlatform(knight);
        drawHUD(sensors);

        window.display();
    }

private:
    void drawKnight(Knight &knight)
    {
        knight.setPosition(knight.position);
        window.draw(knight.sprite);
    }

    void drawHUD(Sensors &sensors)
    {
        /*
        sf::Font font("assets/font.ttf");
        sf::Text text(font);
        sf::String string = "JumpHoldTime = " + std::to_string(sensors.jumpHoldTime);
        text.setString(string);
        text.setCharacterSize(24);
        window.draw(text);
        */

        sf::RectangleShape background(Config::HUD::ProgressBar::SIZE);
        background.setPosition(Config::HUD::ProgressBar::POSITION);
        background.setFillColor(sf::Color::Transparent);
        background.setOutlineColor(Config::HUD::ProgressBar::OUTLINE_COLOR);
        background.setOutlineThickness(Config::HUD::ProgressBar::OUTLINE_THICKNESS);

        float bar_length = Config::HUD::ProgressBar::SIZE.x * (sensors.chargeTime / Config::Sensors::MAX_CHARGE_TIME);

        sf::RectangleShape fill({bar_length, Config::HUD::ProgressBar::SIZE.y});
        fill.setPosition(Config::HUD::ProgressBar::POSITION);
        fill.setFillColor(Config::HUD::ProgressBar::FILL_COLOR);

        window.draw(background);
        window.draw(fill);
    }

    void drawPlatform(Knight &knight)
    {
        sf::RectangleShape platform(Config::Platform::SIZE);
        platform.setOrigin({Config::Platform::SIZE.x / 2, 0});
        platform.setPosition(knight.position);
        platform.setFillColor(Config::Platform::FILL_COLOR);
        platform.setOutlineColor(Config::Platform::OUTLINE_COLOR);
        platform.setOutlineThickness(Config::Platform::OUTLINE_THICKNESS);
        window.draw(platform);
    }

    sf::RenderWindow &window;
};