//
// Created by jack- on 24/09/2022.
//

#ifndef VEC2_H
#define VEC2_H

typedef struct Vec2 Vec2;
struct Vec2 {
    float x, y;
    float limit;

    Vec2();
    Vec2(float x, float y);

    float get_magnitude() const;
    float get_direction() const;

    float dot_product(Vec2* otherVector) const;
    float distance_between(Vec2* otherVector) const;
    float angle_between(Vec2* otherVector) const;

    void add(Vec2* otherVector);
    void sub(Vec2* otherVector);
    void mult(float value);
    void div(float value);

    void normalise();
};

#endif //VEC2_H
