#pragma once

#include <SFML/Graphics.hpp>

class Sensors
{
public:
    void poll(float dt);

    float chargeTime = 0.0f;
    bool chargeIsReleased = false;
    sf::Angle angle = sf::degrees(0);

private:
    void poll_charge(float dt);
    void poll_angle();

    bool jumpWasPressed = false;
};
