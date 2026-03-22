#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Sensors
{
public:
    void poll(float &dt)
    {
        bool jumpPressedNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
        jumpHeld = jumpPressed && jumpPressedNow;
        if (jumpHeld)
            if (chargeTime + dt > Config::Sensors::MAX_CHARGE_TIME)
                chargeTime = Config::Sensors::MAX_CHARGE_TIME;
            else
                chargeTime += dt;
        else
            chargeTime = 0.0f;

        jumpPressed = jumpPressedNow;
    }

    float chargeTime = 0.0f;

private:
    bool jumpPressed = false;
    bool jumpHeld = false;
};