#include <math.h>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "Point.h"
#include "definitions.h"

Point::Point(float x, float y) {
    pos = prevPos = initPos = sf::Vector2f(x, y);
}

void Point::addStick(Stick *stick, int index) { sticks[index] = stick; }

void Point::setPos(float x, float y) { pos.x = x; pos.y = y; }

void Point::pin() { isPinned = true; }

void Point::update(float deltaTime, float drag, const sf::Vector2f acceleration, float elasticity, sf::RenderWindow* window, int cursorSize, sf::Vector2f& mousePrevPos) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse().getPosition(*window).x, sf::Mouse().getPosition(*window).y);
    sf::Vector2f cursorToPosDir = pos - mousePos;
    float cursorToPosDist = sqrtf(cursorToPosDir.x * cursorToPosDir.x + cursorToPosDir.y * cursorToPosDir.y);
    isSelected = cursorToPosDist < cursorSize;

    for(Stick* stick : sticks) {
        if(stick != nullptr)
            stick->setIsSelected(isSelected);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && isSelected) {
        sf::Vector2f difference = mousePos - mousePrevPos;

        if(difference.x > elasticity) difference.x = elasticity;
        if(difference.y > elasticity) difference.y = elasticity;
        if(difference.x < -elasticity) difference.x = -elasticity;
        if(difference.y < -elasticity) difference.y = -elasticity;

        prevPos = pos - difference;
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && isSelected) {
        for(Stick* stick : sticks) {
            if(stick != nullptr) stick->destroy();
        }
    }

    if(isPinned) {
        pos = initPos;
        return;
    }

    sf::Vector2f newPos = pos + (pos - prevPos) * (1.0f - drag) + acceleration * (1.0f - drag) * deltaTime * deltaTime;
    prevPos = pos;
    pos = newPos;

    keepInside();
}

void Point::keepInside() {
    if (pos.x > screenWidth) {
        pos.x = screenWidth;
        prevPos.x = pos.x;
    }
    else if (pos.x < 0) {
        pos.x = 0;
        prevPos.x = pos.x;
    }

    if (pos.y > screenHeight) {
        pos.y = screenHeight;
        prevPos.y = pos.y;
    }
    else if (pos.y < 0) {
        pos.y = 0;
        prevPos.y = pos.y;
    }
}