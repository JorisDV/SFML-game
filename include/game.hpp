#include <SFML/Graphics.hpp>

namespace
{
    constexpr uint16_t WINDOW_WIDTH = 1280;
    constexpr uint16_t WINDOW_HEIGHT = 720;
}

class Game
{
public:
    void start()
    {
        sf::RenderWindow window{sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Test"};
        window.setFramerateLimit(60);

        sf::CircleShape triangle(64.0f);
        triangle.setPointCount(3);
        triangle.setOrigin(triangle.getGeometricCenter());
        triangle.setPosition({WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f});
        triangle.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            triangle.rotate(sf::degrees(1));

            window.clear();
            window.draw(triangle);
            window.display();
        }
    }
};