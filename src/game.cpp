#include <SFML/Graphics.hpp>
#include "../include/game.hpp"

float calculateFPS(int &frame_count, float &timer, float dt, float fps)
{
    timer += dt;
    frame_count++;

    if (timer >= 0.25f)
    {
        fps = frame_count / timer;
        frame_count = 0;
        timer = 0.0f;
    }

    return fps;
}

Game::Game() : window(sf::VideoMode({Config::Window::WIDTH, Config::Window::HEIGHT}), Config::Window::TITLE),
             renderer(window)
    {
        // sf::Image icon(Config::Window::ICON);
        // window.setIcon(icon.getSize(), icon.getPixelsPtr());
        window.setFramerateLimit(Config::Window::FRAMERATE_LIMIT);
    }

void Game::start()
{
    int frame_count = 0;
    float timer = 0.0f;
    float fps = 0.0f;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        fps = calculateFPS(frame_count, timer, dt, fps);

        sensors.poll(dt);
        physics.calculateKnightPosition(knight, world, sensors, dt);
        checkGameOver(window, knight);
        renderer.draw(knight, world, sensors, hud, fps);
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
}

void Game::checkGameOver(sf::RenderWindow &window, Knight &knight)
{
    sf::View view = window.getView();
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();
    float yLevelUndersideView = center.y + (size.y / 2);

    if (knight.position.y - Config::Knight::SIZE > yLevelUndersideView)
        restart();
}