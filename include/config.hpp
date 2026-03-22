#pragma once

namespace Config
{
    struct HUD
    {
        struct ProgressBar
        {
            static constexpr sf::Vector2f SIZE = {150.0f, 25.0f};
            static constexpr sf::Vector2f POSITION = {10.0f, 10.0f};
            static constexpr sf::Color FILL_COLOR = sf::Color::Green;
            static constexpr sf::Color OUTLINE_COLOR = sf::Color::Black;
            static constexpr float OUTLINE_THICKNESS = 4.0f;
        };
    };

    struct Platform
    {
        static constexpr sf::Vector2f SIZE = {120.0f, 18.0f};
        static constexpr sf::Color FILL_COLOR = sf::Color::White;
        static constexpr sf::Color OUTLINE_COLOR = sf::Color::Black;
        static constexpr float OUTLINE_THICKNESS = 4.0f;
    };

    struct Physics
    {
        static constexpr float MAX_CHARGE_TIME = 1.5f;
        static constexpr float MIN_JUMP_SPEED = 300.0f;
        static constexpr float MAX_JUMP_SPEED = 900.0f;
        static constexpr float GRAVITY = 1600.0f;
    };

    struct Window
    {
        static constexpr unsigned int WIDTH = 1280;
        static constexpr unsigned int HEIGHT = 720;
        static constexpr char TITLE[] = "SFML-game";
        static constexpr unsigned int FRAMERATE_LIMIT = 60;
        static constexpr sf::Color BACKGROUND_COLOR = sf::Color(0x2499A6FF);
    };

    struct Knight
    {
        static constexpr unsigned int SIZE = 64;
        static constexpr char TEXTURE[] = "assets/knight.png";
        static constexpr sf::Vector2f INITIAL_POSITION = {Config::Window::WIDTH / 2, Config::Window::HEIGHT * 0.9};
    };
}