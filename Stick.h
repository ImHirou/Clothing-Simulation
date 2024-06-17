#ifndef CLOTHINGSIMULATION_STICK_H
#define CLOTHINGSIMULATION_STICK_H

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Point;
class Stick {
private:
    Point& p0;
    Point& p1;
    float length;

    bool isActive = true;
    bool isSelected = false;

    sf::Color color{255, 255, 255};
    sf::Color colorWhenSelected{200, 0, 0};

public:
    Stick(Point& p0, Point& p1, float length);
    ~Stick() = default;

    void setIsSelected(bool value);

    void update();
    void draw(sf::RenderWindow* window);
    void destroy();
};

#endif //CLOTHINGSIMULATION_STICK_H
