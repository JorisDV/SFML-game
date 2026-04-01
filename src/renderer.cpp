#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"
#include "config.hpp"

Renderer::Renderer(sf::RenderWindow &window) : window(window),
                                               font(Config::HUD::FPSCounter::FONT),
                                               fps_text(font)
{
    fps_text.setCharacterSize(Config::HUD::FPSCounter::SIZE);
    fps_text.setString("FPS: 9999");
    fps_text.setOrigin({fps_text.getGlobalBounds().size.x, 0});
    fps_text.setPosition(Config::HUD::FPSCounter::POSITION);
    fps_text.setFillColor(Config::HUD::FPSCounter::FILL_COLOR);
}

void Renderer::draw(Knight &knight, World &world, Sensors &sensors, HUD &hud, float fps)
{
    window.clear(Config::Window::BACKGROUND_COLOR);

    drawWorld(world);
    drawKnight(knight);
    drawHUD(hud, knight, sensors);
    drawFPS(fps);

    window.display();
}

void Renderer::drawKnight(Knight &knight)
{
    if (knight.hasJustLanded)
    {
        knight.sprite = sf::Sprite(knight.textureOnGround);
        knight.sprite.setScale({static_cast<float>(Config::Knight::SIZE) / 16,
                                static_cast<float>(Config::Knight::SIZE) / 16});
        knight.sprite.setOrigin({8.0f, 16.0f});
        knight.sprite.setPosition(knight.position);
    }

    if (knight.hasJustJumped)
    {
        knight.sprite = sf::Sprite(knight.textureJumping);
        knight.sprite.setScale({static_cast<float>(Config::Knight::SIZE) / 16,
                                static_cast<float>(Config::Knight::SIZE) / 16});
        knight.sprite.setOrigin({8.0f, 16.0f});
        knight.sprite.setPosition(knight.position);
    }

    knight.sprite.setPosition(knight.position);
    window.draw(knight.sprite);
}

void Renderer::drawWorld(World &world)
{
    for (Platform platform : world.platforms)
    {
        window.draw(platform.rect);
    }
}

void Renderer::drawHUD(HUD &hud, Knight &knight, Sensors &sensors)
{
    if (knight.hasJustLanded)
        hud.arrow.reset(knight, sensors);

    if (knight.isOnGround)
    {
        hud.arrow.update(sensors.angle);
        window.draw(hud.arrow.line);
        window.draw(hud.arrow.triangle);
    }

    hud.progress_bar.update(sensors);
    window.draw(hud.progress_bar.background);
    window.draw(hud.progress_bar.fill);
}

void Renderer::drawFPS(float fps)
{
    fps_text.setString("FPS: " + std::to_string((int)fps));
    window.draw(fps_text);
}