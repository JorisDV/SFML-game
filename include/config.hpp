#pragma once

#include <filesystem>
#include <numbers>
#include <cmath>
#include <SFML/Graphics.hpp>

namespace Config
{
    const std::filesystem::path ASSETS_DIRECTORY = "../assets";

    struct Window
    {
        static constexpr unsigned int WIDTH = 1280;
        static constexpr unsigned int HEIGHT = 1280;
        static constexpr char TITLE[] = "SFML-game";
        static inline const std::filesystem::path ICON = Config::ASSETS_DIRECTORY / "icon.png";
        static constexpr unsigned int FRAMERATE_LIMIT = 60;
        static constexpr sf::Color BACKGROUND_COLOR = sf::Color(0x2499A6FF);
        static constexpr float CAMERA_FOLLOW_THRESHOLD_Y = 0.65f * Config::Window::HEIGHT;
    };

    struct Knight
    {
        static constexpr unsigned int SIZE = 64;
        static inline const std::filesystem::path SPRITESHEET = Config::ASSETS_DIRECTORY / "knight.png";
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
            static constexpr sf::Color COLOR = sf::Color::Red;
            static constexpr sf::Color OUTLINE_COLOR = sf::Color::Black;
            static constexpr float OUTLINE_THICKNESS = 2.0f;
            static constexpr float HEIGHT_ABOVE_KNIGHT = 10.0f;
        };
    };

    struct Platform
    {
        static constexpr sf::Vector2f SIZE = {320.0f, 18.0f};
        static constexpr sf::Color FILL_COLOR = sf::Color::White;
        static constexpr sf::Color OUTLINE_COLOR = sf::Color::Black;
        static constexpr float OUTLINE_THICKNESS = 4.0f;
    };

    struct World
    {
        static constexpr unsigned int NR_OF_PLATFORMS = 15;
        static constexpr float MIN_PLATFORM_SPACING = 10.0f + Config::Platform::SIZE.y + 2 * Config::Platform::OUTLINE_THICKNESS;
        static constexpr float PLATFORM_HEIGHT_BIAS = 0.4f; // lower -> further apart, higher -> closer together
        static constexpr float PLATFORM_HEIGHT_SPREAD = 0.3f;
    };

    struct Physics
    {
        static constexpr float MAX_CHARGE_TIME = 1.5f;
        static constexpr float MIN_JUMP_SPEED = 300.0f;
        static constexpr float MAX_JUMP_SPEED = 1200.0f;
        static constexpr float GRAVITY = 1600.0f;
        static constexpr float MAX_NEEDED_ANGLE = 35.0f * std::numbers::pi_v<float> / 180.0f;
        static inline const float MAX_JUMP_HEIGHT = pow(std::cos(Config::Physics::MAX_NEEDED_ANGLE) * Config::Physics::MAX_JUMP_SPEED, 2) / (2 * Config::Physics::GRAVITY);
        static constexpr sf::Angle ANGLE_STEP = sf::degrees(1);
        static constexpr sf::Angle MAX_ANGLE = sf::degrees(60);
    };
}
