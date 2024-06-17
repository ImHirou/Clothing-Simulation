#include <math.h>
#include <SFML/Graphics.hpp>
#include "Stick.h"
#include "Point.h"

Stick::Stick(Point &p0, Point &p1, float length) : p0(p0), p1(p1), length(length) {}

void Stick::update() {
    if(!isActive) return;

    sf::Vector2f p0Pos = p0.getPos();
    sf::Vector2f p1Pos = p1.getPos();

    sf::Vector2f diff = p0Pos - p1Pos;
    float dist = sqrtf(diff.x * diff.x + diff.y * diff.y);
    float diffFactor = (length - dist) / dist;
    sf::Vector2f offset = diff * diffFactor * 0.5f;

    p0.setPos(p0Pos.x + offset.x, p0Pos.y + offset.y);
    p1.setPos(p1Pos.x - offset.x, p1Pos.y - offset.y);

}

void Stick::draw(sf::RenderWindow *window) {
    if(!isActive) return;

    sf::Vector2f p0Pos = p0.getPos();
    sf::Vector2f p1Pos = p1.getPos();

    sf::Vertex line[] = {
            sf::Vertex(p0Pos),
            sf::Vertex(p1Pos)
    };

    if(!isSelected) {
        line[0].color = color;
        line[1].color = color;
    } else {
        line[0].color = colorWhenSelected;
        line[1].color = colorWhenSelected;
    }

    window->draw(line, 2, sf::Lines);

}

void Stick::destroy() { isActive = false; }

void Stick::setIsSelected(bool value) { isSelected = value; }