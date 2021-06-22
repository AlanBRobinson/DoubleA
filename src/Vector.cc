#pragma once
#include "Vector.h"
#include <math.h>

Vector::Vector(float x, float y) {
  this->x = x;
  this->y = y;
}

float Vector::getAngle() {

  Vector * direction = new Vector(2, 1);
  auto angle = direction->getAngle();

  return std::atan2(y, x);
}

Vector Vector::setAngle(float angle) {
  auto magnitude = this->getMagnitude();
  return Vector(
    std::cos(angle) * magnitude,
    std::sin(angle) * magnitude
  );
}

float Vector::getMagnitude() {
  return std::sqrt(this->x * this->x + this->y * this->y);
}

Vector Vector::setMangnitude(float magnitude) {
  auto currentMagnitude = this->getMagnitude();
  if(!currentMagnitude) {
    return Vector(this->x, this->y);
  }

  float factor = magnitude / this->getMagnitude();
  return Vector(
    this->x *= factor,
    this->y *= factor
  );
}

Vector Vector::addVector(Vector vector) {
  return Vector(
    this->x + vector.x,
    this->y + vector.y
  );
}

Vector Vector::normalize() {
  this->setMangnitude(1);
}
