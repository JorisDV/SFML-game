#pragma once

namespace Config
{
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

        struct Arrow
        {
            static constexpr sf::Vector2f SIZE_LINE = {5.0f, 80.0f};
            static constexpr float SIZE_TRIANGLE = 16.0f;
            static constexpr sf::Color COLOR = sf::Color::White;
            static constexpr float HEIGHT_ABOVE_KNIGHT = 10.0f;
        };

        struct FPSCounter
        {
            static constexpr int SIZE = 24;
            static constexpr sf::Vector2f POSITION = {Config::Window::WIDTH - 10.0f, 10.0f};
            static constexpr sf::Color FILL_COLOR = sf::Color::White;
            static constexpr char FONT[] = "assets/font.ttf";
        };
    };

    struct Platform
    {
        static constexpr sf::Vector2f SIZE = {320.0f, 18.0f};
        static constexpr sf::Color FILL_COLOR = sf::Color::White;
        static constexpr sf::Color OUTLINE_COLOR = sf::Color::Black;
        static constexpr float OUTLINE_THICKNESS = 4.0f;
    };

    struct Physics
    {
        static constexpr float MAX_CHARGE_TIME = 1.5f;
        static constexpr float MIN_JUMP_SPEED = 300.0f;
        static constexpr float MAX_JUMP_SPEED = 1200.0f;
        static constexpr float GRAVITY = 1600.0f;
        static constexpr sf::Angle ANGLE_STEP = sf::degrees(1);
        static constexpr sf::Angle MAX_ANGLE = sf::degrees(60);
    };
}