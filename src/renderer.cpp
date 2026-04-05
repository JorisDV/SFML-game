#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "knight.hpp"
#include "world.hpp"
#include "hud.hpp"
#include "config.hpp"

Renderer::Renderer(sf::RenderWindow &window) : window(window) {}

void Renderer::draw(Knight &knight, World &world, Sensors &sensors, HUD &hud)
{
    window.clear(Config::Window::BACKGROUND_COLOR);
    view = window.getView();

    drawWorld(world);
    drawKnight(knight);
    drawHUD(hud, knight, sensors);

    window.setView(view);
    window.display();
}

void Renderer::drawWorld(World &world)
{
    for (Platform platform : world.platforms)
    {
        window.draw(platform.rect);
    }
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

    window.setView(window.getDefaultView());
    hud.progress_bar.update(sensors);
    window.draw(hud.progress_bar.background);
    window.draw(hud.progress_bar.fill);

    hud.score.update(knight);
    window.draw(hud.score.background);
    window.draw(hud.score.text);
}
