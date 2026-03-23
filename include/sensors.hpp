#pragma once

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Sensors
{
public:
    void poll(float dt)
    {
        poll_charge(dt);
        poll_angle();
    }

    float chargeTime = 0.0f;
    bool chargeIsReleased = false;
    sf::Angle angle = sf::degrees(0);

private:
    void poll_charge(float dt)
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

    void poll_angle()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            if (angle - Config::Physics::ANGLE_STEP > -Config::Physics::MAX_ANGLE)
                angle -= Config::Physics::ANGLE_STEP;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            if (angle + Config::Physics::ANGLE_STEP < Config::Physics::MAX_ANGLE)
                angle += Config::Physics::ANGLE_STEP;
    }

    bool jumpWasPressed = false;
};