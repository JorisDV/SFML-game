#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Sensors
{
public:
    void poll(float dt)
    {
        chargeIsReleased = false;

        bool jumpIsPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
        if (jumpWasPressed && jumpIsPressed)
            if (chargeTime + dt > Config::Physics::MAX_CHARGE_TIME)
                chargeTime = Config::Physics::MAX_CHARGE_TIME;
            else
                chargeTime += dt;

        else if (jumpWasPressed && !jumpIsPressed)
            chargeIsReleased = true;

        else
            chargeTime = 0.0f;

        jumpWasPressed = jumpIsPressed;
    }

    float chargeTime = 0.0f;
    bool chargeIsReleased = false;

private:
    bool jumpWasPressed = false;
};