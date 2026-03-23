#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"
#include "sensors.hpp"

class ProgressBar
{
public:
    ProgressBar() : background(Config::HUD::ProgressBar::SIZE)
    {
        background.setPosition(Config::HUD::ProgressBar::POSITION);
        background.setFillColor(sf::Color::Transparent);
        background.setOutlineColor(Config::HUD::ProgressBar::OUTLINE_COLOR);
        background.setOutlineThickness(Config::HUD::ProgressBar::OUTLINE_THICKNESS);

        fill.setPosition(Config::HUD::ProgressBar::POSITION);
        fill.setFillColor(Config::HUD::ProgressBar::FILL_COLOR);
    }

    void update(Sensors &sensors)
    {
        float bar_length = Config::HUD::ProgressBar::SIZE.x * (sensors.chargeTime / Config::Physics::MAX_CHARGE_TIME);
        fill.setSize({bar_length, Config::HUD::ProgressBar::SIZE.y});
    }

    sf::RectangleShape background;
    sf::RectangleShape fill;

private:
    float bar_length;
};

class Arrow
{
public:
    Arrow() : line(Config::HUD::Arrow::SIZE_LINE),
              triangle(Config::HUD::Arrow::SIZE_TRIANGLE, 3)
    {
        line.setOrigin({Config::HUD::Arrow::SIZE_LINE.x / 2, Config::HUD::Arrow::SIZE_LINE.y});
        line.setPosition({Config::Knight::INITIAL_POSITION.x, Config::Knight::INITIAL_POSITION.y - Config::Knight::SIZE - Config::HUD::Arrow::HEIGHT_ABOVE_KNIGHT});
        line.setFillColor(Config::HUD::Arrow::COLOR);

        triangle.setOrigin({Config::HUD::Arrow::SIZE_TRIANGLE, Config::HUD::Arrow::SIZE_TRIANGLE + Config::HUD::Arrow::SIZE_LINE.y});
        triangle.setPosition(line.getPosition());
        triangle.setFillColor(Config::HUD::Arrow::COLOR);
    }

    void update(sf::Angle angle)
    {
        line.setRotation(angle);
        triangle.setRotation(angle);
    }

    void reset(Knight &knight, Sensors &sensors)
    {
        line.setPosition({knight.position.x, knight.position.y - Config::Knight::SIZE - Config::HUD::Arrow::HEIGHT_ABOVE_KNIGHT});
        triangle.setPosition(line.getPosition());
        sensors.angle = sf::degrees(0);
    }

    sf::RectangleShape line;
    sf::CircleShape triangle;
};

class HUD
{
public:
    ProgressBar progress_bar;
    Arrow arrow;
};