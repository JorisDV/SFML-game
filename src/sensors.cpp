#include <SFML/Graphics.hpp>
#include "sensors.hpp"
#include "config.hpp"

void Sensors::poll(float dt)
{
    poll_charge(dt);
    poll_angle();
}

void Sensors::poll_charge(float dt)
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

void Sensors::poll_angle()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        if (angle - Config::Physics::ANGLE_STEP > -Config::Physics::MAX_ANGLE)
            angle -= Config::Physics::ANGLE_STEP;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        if (angle + Config::Physics::ANGLE_STEP < Config::Physics::MAX_ANGLE)
            angle += Config::Physics::ANGLE_STEP;
}
