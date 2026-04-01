#pragma once

#include "knight.hpp"
#include "world.hpp"
#include "sensors.hpp"

class Physics
{
public:
    void calculateKnightPosition(Knight &knight, World &world, Sensors &sensors, float dt);

private:
    bool knightHasLanded(Knight &knight, Platform &platform);
};
