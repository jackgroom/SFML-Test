//
// Created by jack- on 24/09/2022.
//

#include "../util/Vec2.h"
#include <SFML/Graphics.hpp>

#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct Circle Circle;
struct Circle {
    float radius;
    sf::Color color;

    sf::CircleShape circle;

    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;

    Circle(float radius, sf::Color color);

    void applyForce(Vec2* force);
    void edges();
    void update();

    void getRandomColour();

    sf::CircleShape render();
};

#endif //CIRCLE_H
