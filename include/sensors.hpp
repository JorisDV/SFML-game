#pragma once

#include <SFML/Graphics.hpp>

class Sensors
{
public:
    sf::Vector2f direction;
    float intensity;

    void poll(float dt)
    {
        bool jumpPressedNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
        jumpHeld = jumpPressed && jumpPressedNow;
        if (jumpHeld)
            jumpHoldTime += dt;
        else
            jumpHoldTime = 0.0f;

        jumpPressed = jumpPressedNow;
    }

    bool jumpPressed = false;
    bool jumpHeld = false;
    float jumpHoldTime = 0.0f;
};