#include "Mouse.h"

void Mouse::setPosition(const sf::Vector2i &position, sf::RenderWindow& window) {
    prevPos = sf::Vector2f(getPosition(window).x, getPosition(window).y);
    sf::Mouse::setPosition(position);
}

void Mouse::IncreaseCursorSize(float increment) {
    if(cursorSize + increment > maxCursorSize || cursorSize + increment < minCursorSize) return;
    cursorSize += increment;
}