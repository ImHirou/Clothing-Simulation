#include <SFML/Graphics.hpp>
#include "definitions.h"
#include "Cloth.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Cloth");

    Cloth cloth(20, 20, 20, 100, 100);
    sf::Clock clock;
    uint32_t lastUpdateTime = clock.getElapsedTime().asMilliseconds();
    sf::Vector2f mousePrevPos(0, 0);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = (clock.getElapsedTime().asMilliseconds() - lastUpdateTime) / 1000.0f;
        cloth.update(&window,deltaTime, mousePrevPos);
        clock.restart();
        lastUpdateTime = clock.getElapsedTime().asMilliseconds();

        window.clear(sf::Color::Black);
        cloth.draw(&window);
        window.display();

        mousePrevPos = sf::Vector2f (sf::Mouse().getPosition().x, sf::Mouse().getPosition().y);

    }

    return 0;
}
