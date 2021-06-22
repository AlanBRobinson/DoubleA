#pragma once

class Vector {
  public:
    Vector(float x, float y);
    float x = 0;
    float y = 0;

    float getAngle();
    Vector setAngle(float angle);

    float getMagnitude();
    Vector setMangnitude(float magnitude);

    Vector addVector(Vector vector);
    Vector normalize();
};
