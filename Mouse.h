#ifndef CLOTHINGSIMULATION_MOUSE_H
#define CLOTHINGSIMULATION_MOUSE_H

#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Mouse : public sf::Mouse {
private:
    sf::Vector2f prevPos;
    float maxCursorSize = 100;
    float minCursorSize = 20;

    float cursorSize = 20;
public:
    Mouse() = default;
    ~Mouse() = default;

    const sf::Vector2f& getPreviousPos() const { return prevPos; }

    void IncreaseCursorSize(float increment);
    float getCursorSize() const { return cursorSize; }

    void setPosition(const sf::Vector2i &position, sf::RenderWindow& window);
};


#endif //CLOTHINGSIMULATION_MOUSE_H
