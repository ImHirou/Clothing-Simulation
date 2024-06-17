#include "Cloth.h"
#include "definitions.h"

Cloth::Cloth(int width, int height, int spacing, int startX, int startY) {
    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++)
        {
            Point* point = new Point(startX + x * spacing, startY + y * spacing);

            if (x != 0)
            {
                Point* leftPoint = points[this->points.size() - 1];
                Stick* s = new Stick(*point, *leftPoint, spacing);
                leftPoint->addStick(s, 0);
                point->addStick(s, 0);
                sticks.push_back(s);
            }

            if (y != 0)
            {
                Point* upPoint = points[x + (y - 1) * (width + 1)];
                Stick* s = new Stick(*point, *upPoint, spacing);
                upPoint->addStick(s, 1);
                point->addStick(s, 1);
                sticks.push_back(s);
            }

            if (y == 0 && x % 2 == 0)
            {
                point->pin();
            }

            points.push_back(point);
        }
    }
}

void Cloth::update(sf::RenderWindow *window, float deltaTime, sf::Vector2f& mousePrevPos) {
    for (int i = 0; i < points.size(); i++)
    {
        Point* p = points[i];
        p->update(deltaTime, drag, gravity, elasticity, window, 20, mousePrevPos);
    };

    for (int i = 0; i < sticks.size(); i++)
    {
        sticks[i]->update();
    };
}

void Cloth::draw(sf::RenderWindow *window) {
    for(int i=0; i < sticks.size(); i++) sticks[i]->draw(window);
}

Cloth::~Cloth()
{
    for (auto point : points)
    {
        delete point;
    }

    for (auto stick : sticks)
    {
        delete stick;
    }
}