//
// Created by jack- on 24/09/2022.
//

#include <cmath>

#include "Vec2.h"

// ---------------------------------------------------------------------------------------------------------------------

Vec2::Vec2()
{
    this->x = 0;
    this->y = 0;
    this->limit = 0;
}

Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
    this->limit = 0;
}

// ---------------------------------------------------------------------------------------------------------------------

float Vec2::get_magnitude() const
{
    float magnitude = std::sqrt(std::pow(this->x, 2.0f) + std::pow(this->y, 2.0f));

    return this->limit > 0
        ? magnitude < this->limit
            ? magnitude
            : this->limit
        : magnitude;
}

float Vec2::get_direction() const
{
    return std::atan(this->y / this->x);
}

// ---------------------------------------------------------------------------------------------------------------------

float Vec2::dot_product(Vec2* otherVector) const
{
    return this->x * otherVector->x + this->y * otherVector->y;
}

float Vec2::distance_between(Vec2* otherVector) const
{
    return std::sqrt(std::pow(this->x - otherVector->x, 2.0f) + std::pow(this->y - otherVector->y, 2.0f));
}

float Vec2::angle_between(Vec2* otherVector) const
{
    return this->dot_product(otherVector) / (this->get_magnitude() * otherVector->get_magnitude());
}

// ---------------------------------------------------------------------------------------------------------------------

void Vec2::add(Vec2 *otherVector)
{
    this->x += otherVector->x;
    this->y += otherVector->y;
}

void Vec2::sub(Vec2 *otherVector)
{
    this->x -= otherVector->x;
    this->y -= otherVector->y;
}

void Vec2::mult(float value)
{
    this->x *= value;
    this->y *= value;
}

void Vec2::div(float value)
{
    this->x /= value;
    this->y /= value;
}

// ---------------------------------------------------------------------------------------------------------------------

void Vec2::normalise()
{
    this->div(this->get_magnitude());
}

// ---------------------------------------------------------------------------------------------------------------------

