#include <cmath>
#include <numbers>
#include <SFML/Graphics.hpp>
#include "physics.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "sensors.hpp"
#include "config.hpp"

void Physics::calculateKnightPosition(Knight &knight, World &world, Sensors &sensors, float dt)
{
    knight.hasJustLanded = false;
    knight.prev_position_y = knight.position.y;
    knight.hasJustJumped = false;

    if (sensors.chargeIsReleased && knight.isOnGround)
    {
        float charge = sensors.chargeTime / Config::Physics::MAX_CHARGE_TIME;
        float angle = (std::numbers::pi / 2) - sensors.angle.asRadians();
        float jumpSpeed = Config::Physics::MIN_JUMP_SPEED + charge * (Config::Physics::MAX_JUMP_SPEED - Config::Physics::MIN_JUMP_SPEED);
        knight.velocity = {jumpSpeed * std::cos(angle), -jumpSpeed * std::sin(angle)};
        knight.isOnGround = false;
        knight.hasJustJumped = true;
    }

    if (!knight.isOnGround)
    {
        knight.velocity.y += Config::Physics::GRAVITY * dt;
        knight.position += knight.velocity * dt;

        for (Platform platform : world.platforms)
            if (knightHasLanded(knight, platform))
            {
                knight.velocity = {0.0f, 0.0f};
                knight.position.y = platform.position.y;
                knight.isOnGround = true;
                knight.hasJustLanded = true;
            }
    }
}

bool Physics::knightHasLanded(Knight &knight, Platform &platform)
{
    bool isFalling = knight.velocity.y > 0;
    bool crossedPlatfomY = knight.prev_position_y < platform.position.y && platform.position.y <= knight.position.y;
    bool withinPlatformX = platform.position.x - (Config::Platform::SIZE.x / 2) - Config::Platform::OUTLINE_THICKNESS < knight.position.x - (1 / 3) * Config::Knight::SIZE && knight.position.x + (1 / 3) * Config::Knight::SIZE < platform.position.x + (Config::Platform::SIZE.x / 2) + Config::Platform::OUTLINE_THICKNESS;

    if (isFalling && crossedPlatfomY && withinPlatformX)
        return true;

    return false;
}