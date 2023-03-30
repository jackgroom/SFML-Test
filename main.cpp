#include <SFML/Graphics.hpp>

#include "game/Circle.h"
#include "game/Game.h"

//#include "util/Vec2.h"


int main()
{
    Game game;
    Game* gamePtr = &game;

    Circle bouncingCircle = Circle(40.0f, sf::Color::Blue);
    Circle* bouncingCirclePtr = &bouncingCircle;

    Vec2 initialForce = Vec2(0.2, 0);
    bouncingCirclePtr->applyForce(&initialForce);
    gamePtr->add_render(bouncingCirclePtr);
    gamePtr->beginGameLoop();
}
