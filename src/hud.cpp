#include <string>
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

Score::Score() : font(Config::HUD::Score::FONT),
                 text(font),
                 score(0),
                 prev_score_length(1)
{
    text.setCharacterSize(Config::HUD::Score::SIZE);
    text.setFillColor(Config::HUD::Score::COLOR);
    text.setOutlineColor(Config::HUD::Score::OUTLINE_COLOR);
    text.setOutlineThickness(Config::HUD::Score::OUTLINE_THICKNESS);
    text.setLetterSpacing(Config::HUD::Score::LETTER_SPACING);
    text.setString(Config::HUD::Score::STRING + "0");
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({bounds.size.x / 2.0f + bounds.position.x, bounds.position.y});
    sf::Vector2f text_position = Config::HUD::Score::POSITION;
    text.setPosition(text_position);

    background.setPosition({text_position.x - bounds.size.x / 2.0f, text_position.y});
    background.setSize(bounds.size);
    background.setFillColor(sf::Color::Red);
    background.setOutlineColor(background.getFillColor());
    background.setOutlineThickness(Config::HUD::Score::OUTLINE_THICKNESS);
}

void Score::update(Knight &knight)
{
    score = static_cast<unsigned int>(Config::Knight::INITIAL_POSITION.y - knight.highest_y);
    std::string score_string = std::to_string(score);
    text.setString(Config::HUD::Score::STRING + score_string);

    size_t score_length = score_string.length();
    if (score_length != prev_score_length)
    {
        background.setSize(text.getLocalBounds().size);
        prev_score_length = score_length;
    }
}

void HUD::reset(Knight &knight, Sensors &sensors)
{
    arrow.reset(knight, sensors);
}
