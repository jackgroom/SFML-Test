//
// Created by jack- on 24/09/2022.
//
#include <random>

#include "Circle.h"

#include "../util/Vec2.h"
#include <SFML/Graphics.hpp>

// ---------------------------------------------------------------------------------------------------------------------

Circle::Circle(float radius, sf::Color color)
{
    this->radius = radius;
    this->color = color;
    this->position = Vec2(100, 100);
}

// ---------------------------------------------------------------------------------------------------------------------

void Circle::applyForce(Vec2* force)
{
    this->acceleration.add(force);
}

void Circle::edges()
{
    // not a fan of hard-coding in width and height but oh well

    float width = 640;
    float height = 480;


    if (this->position.x + (this->radius / 2) >= width || this->position.x + (this->radius / 2) <= 0)
    {
        this->velocity.x *= -1;
        this->getRandomColour();
    } else if (this->position.y + (this->radius / 2) >= height) {
        this->velocity.y *= -1;
        this->getRandomColour();
    }
}

void Circle::update()
{
    Vec2 gravity = Vec2(0, 0.0002);

    this->applyForce(&gravity);

    this->velocity.add(&this->acceleration);
    this->position.add(&this->velocity);
    this->acceleration.mult(0.0f);

    this->edges();

    this->circle.setPosition(this->position.x, this->position.y);
}

// ---------------------------------------------------------------------------------------------------------------------

void Circle::getRandomColour()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 255);

    sf::Color randomColour = sf::Color(dist(rng), dist(rng), dist(rng));
    this->color = randomColour;
}

// ---------------------------------------------------------------------------------------------------------------------

sf::CircleShape Circle::render()
{
    this->circle.setRadius(this->radius);
    this->circle.setFillColor(this->color);

    return this->circle;
}

// ---------------------------------------------------------------------------------------------------------------------
