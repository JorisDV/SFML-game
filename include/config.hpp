#pragma once

namespace Config
{
    struct Window
    {
        static constexpr unsigned int WIDTH = 1280;
        static constexpr unsigned int HEIGHT = 720;
        static constexpr char TITLE[] = "SFML-game";
    };

    struct Knight
    {
        static constexpr unsigned int SIZE = 64;
    };

    constexpr unsigned int FRAMERATE_LIMIT = 60;
}