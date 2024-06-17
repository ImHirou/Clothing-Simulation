#ifndef CLOTHINGSIMULATION_CLOTH_H
#define CLOTHINGSIMULATION_CLOTH_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Point.h"
#include "Stick.h"

class Cloth {
private:
    sf::Vector2f gravity{0.0f, 981.0f};
    float drag = 0.01f;
    float elasticity = 10.0f;

    std::vector<Point*> points;
    std::vector<Stick*> sticks;
public:
    Cloth() = default;
    Cloth(int width, int height, int spacing, int startX, int startY);
    ~Cloth();

    void update(sf::RenderWindow* window, float deltaTime, sf::Vector2f& mousePrevPos);
    void draw(sf::RenderWindow* window);

};


#endif //CLOTHINGSIMULATION_CLOTH_H
