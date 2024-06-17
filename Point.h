#ifndef CLOTHINGSIMULATION_POINT_H
#define CLOTHINGSIMULATION_POINT_H

#include "Stick.h"
#include "Mouse.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"

class Point {
private:
    Stick* sticks[2] { nullptr };

    sf::Vector2f pos;
    sf::Vector2f prevPos;
    sf::Vector2f initPos;
    bool isPinned = false;

    bool isSelected = false;

    void keepInside();

public:
    Point();
    Point(float x, float y);
    ~Point() = default;

    void addStick(Stick* stick, int index);

    const sf::Vector2f getPos() const { return pos; }
    void setPos(float x, float y);

    void pin();

    void update(float deltaTime, float drag, const sf::Vector2f acceleration, float elasticity, sf::RenderWindow* window, int cursorSize, sf::Vector2f& mousePrevPos);
};


#endif //CLOTHINGSIMULATION_POINT_H
