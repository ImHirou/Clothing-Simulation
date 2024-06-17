#include <SFML/Graphics.hpp>
#include "iostream"
#include "definitions.h"
#include "Cloth.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Cloth");

    Cloth cloth(60, 40, 10, 100, 100);
    sf::Clock clock;
    uint32_t lastUpdateTime = clock.getElapsedTime().asMilliseconds();
    sf::Vector2f mousePrevPos(0, 0);
    int cursorSize = 20;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseWheelScrolled) {
                cursorSize += event.mouseWheelScroll.delta;
            }
        }


        window.clear(sf::Color::Black);
        cloth.draw(&window);
        float deltaTime = (clock.getElapsedTime().asMilliseconds() - lastUpdateTime) / 1000.0f;
        lastUpdateTime = clock.getElapsedTime().asMilliseconds();
        cloth.update(&window,deltaTime, mousePrevPos, cursorSize);
        window.display();

        mousePrevPos = sf::Vector2f (sf::Mouse().getPosition(window).x, sf::Mouse().getPosition(window).y);

        std::cout << clock.getElapsedTime().asMilliseconds() << " " << lastUpdateTime << " " << clock.getElapsedTime().asMilliseconds() - lastUpdateTime << "\n";


    }

    return 0;
}
