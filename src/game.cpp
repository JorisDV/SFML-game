#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "config.hpp"
#include "physics.hpp"
#include "renderer.hpp"
#include "sensors.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"

Game::Game() : window(sf::VideoMode({Config::Window::WIDTH, Config::Window::HEIGHT}), Config::Window::TITLE),
               renderer(window),
               view(window.getDefaultView()),
               highest_y(Config::Knight::INITIAL_POSITION.y)
{
    sf::Image icon(Config::Window::ICON);
    window.setIcon(icon.getSize(), icon.getPixelsPtr());
    window.setFramerateLimit(Config::Window::FRAMERATE_LIMIT);
}

void Game::start()
{
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        sensors.poll(dt);
        physics.calculateKnightPosition(knight, world, sensors, dt);

        if (knight.position.y < highest_y)
        {
            if (highest_y < Config::Window::CAMERA_FOLLOW_THRESHOLD_Y)
            {
                float diff = highest_y - knight.position.y;
                sf::Vector2f center = view.getCenter();
                center.y -= diff;
                view.setCenter(center);
                window.setView(view);
            }
            highest_y = knight.position.y;
        }

        checkGameOver(window, knight);
        renderer.draw(knight, world, sensors, hud);
    }
}

void Game::restart()
{
    knight.position = Config::Knight::INITIAL_POSITION;
    knight.sprite = sf::Sprite(knight.textureOnGround);
    knight.sprite.setScale({static_cast<float>(Config::Knight::SIZE) / 16,
                            static_cast<float>(Config::Knight::SIZE) / 16});
    knight.sprite.setOrigin({8.0f, 16.0f});
    knight.sprite.setPosition(knight.position);
    knight.sprite.setPosition(knight.position);
    knight.velocity = {0.0f, 0.0f};
    knight.isOnGround = true;
    hud.arrow.reset(knight, sensors);
    world.reset();
    view.setCenter({Config::Window::WIDTH / 2, Config::Window::HEIGHT / 2});
    window.setView(view);
    highest_y = Config::Knight::INITIAL_POSITION.y;
}

void Game::checkGameOver(sf::RenderWindow &window, Knight &knight)
{
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();
    float y_level_underside_view = center.y + (size.y / 2);

    if (knight.position.y > y_level_underside_view)
        restart();
}
