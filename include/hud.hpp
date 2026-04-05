#pragma once

#include <string>
#include <SFML/Graphics.hpp>
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

class Score
{
public:
    Score();

    void update(Knight &knight);
    void reset();

    sf::RectangleShape background;

private:
    sf::Font font;
    size_t prev_score_length;
    unsigned int score;

public:
    sf::Text text;
};

class HUD
{
public:
    ProgressBar progress_bar;
    Arrow arrow;
    Score score;

    void reset(Knight &knight, Sensors &sensors);
};
