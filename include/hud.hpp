#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"
#include "sensors.hpp"

class ProgressBar
{
public:
    ProgressBar();

    void update(Sensors &sensors);

    sf::RectangleShape background;
    sf::RectangleShape fill;

private:
    float bar_length;
};

class Arrow
{
public:
    Arrow();

    void update(sf::Angle angle);
    void reset(Knight &knight, Sensors &sensors);

    sf::RectangleShape line;
    sf::CircleShape triangle;
};

class HUD
{
public:
    ProgressBar progress_bar;
    Arrow arrow;
};