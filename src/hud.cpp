#include <SFML/Graphics.hpp>
#include "hud.hpp"
#include "config.hpp"
#include "knight.hpp"
#include "sensors.hpp"

ProgressBar::ProgressBar() : background(Config::HUD::ProgressBar::SIZE)
{
    background.setPosition(Config::HUD::ProgressBar::POSITION);
    background.setFillColor(Config::Window::BACKGROUND_COLOR);
    background.setOutlineColor(Config::HUD::ProgressBar::OUTLINE_COLOR);
    background.setOutlineThickness(Config::HUD::ProgressBar::OUTLINE_THICKNESS);

    fill.setPosition(Config::HUD::ProgressBar::POSITION);
    fill.setFillColor(Config::HUD::ProgressBar::FILL_COLOR);
}

void ProgressBar::update(Sensors &sensors)
{
    float bar_length = Config::HUD::ProgressBar::SIZE.x * (sensors.chargeTime / Config::Physics::MAX_CHARGE_TIME);
    fill.setSize({bar_length, Config::HUD::ProgressBar::SIZE.y});
}

Arrow::Arrow() : line(Config::HUD::Arrow::SIZE_LINE),
                 triangle(Config::HUD::Arrow::SIZE_TRIANGLE, 3)
{
    line.setOrigin({Config::HUD::Arrow::SIZE_LINE.x / 2, Config::HUD::Arrow::SIZE_LINE.y});
    line.setPosition({Config::Knight::INITIAL_POSITION.x, Config::Knight::INITIAL_POSITION.y - Config::Knight::SIZE - Config::HUD::Arrow::HEIGHT_ABOVE_KNIGHT});
    line.setFillColor(Config::HUD::Arrow::COLOR);
    line.setOutlineColor(Config::HUD::Arrow::OUTLINE_COLOR);
    line.setOutlineThickness(Config::HUD::Arrow::OUTLINE_THICKNESS);

    triangle.setOrigin({Config::HUD::Arrow::SIZE_TRIANGLE, Config::HUD::Arrow::SIZE_TRIANGLE + Config::HUD::Arrow::SIZE_LINE.y});
    triangle.setPosition(line.getPosition());
    triangle.setFillColor(Config::HUD::Arrow::COLOR);
    triangle.setOutlineColor(Config::HUD::Arrow::OUTLINE_COLOR);
    triangle.setOutlineThickness(Config::HUD::Arrow::OUTLINE_THICKNESS);
}

void Arrow::update(sf::Angle angle)
{
    line.setRotation(angle);
    triangle.setRotation(angle);
}

void Arrow::reset(Knight &knight, Sensors &sensors)
{
    line.setPosition({knight.position.x, knight.position.y - Config::Knight::SIZE - Config::HUD::Arrow::HEIGHT_ABOVE_KNIGHT});
    triangle.setPosition(line.getPosition());
    sensors.angle = sf::degrees(0);
}
