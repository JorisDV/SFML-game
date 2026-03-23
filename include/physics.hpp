#pragma once

#include <cmath>
#include <numbers>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "sensors.hpp"

class Physics
{
public:
    void calculateKnightPosition(Knight &knight, World &world, Sensors &sensors, float dt)
    {
        knight.hasJustLanded = false;

        if (sensors.chargeIsReleased && knight.isOnGround)
        {
            float charge = sensors.chargeTime / Config::Physics::MAX_CHARGE_TIME;
            float angle = (std::numbers::pi / 2) - sensors.angle.asRadians();
            float jumpSpeed = Config::Physics::MIN_JUMP_SPEED + charge * (Config::Physics::MAX_JUMP_SPEED - Config::Physics::MIN_JUMP_SPEED);
            knight.velocity = {jumpSpeed * std::cos(angle), -jumpSpeed * std::sin(angle)};
            knight.isOnGround = false;
        }

        if (!knight.isOnGround)
        {
            knight.velocity.y += Config::Physics::GRAVITY * dt;
            knight.position += knight.velocity * dt;
            knight.sprite.setPosition(knight.position);

            for (Platform platform : world.platforms)
                if (knight.sprite.getGlobalBounds().findIntersection(platform.rect.getGlobalBounds()))
                {
                    knight.velocity = {0.0f, 0.0f};
                    knight.position = platform.position;
                    knight.sprite.setPosition(knight.position);
                    knight.isOnGround = true;
                    knight.hasJustLanded = true;
                }
        }
    }
};