#pragma once
#include "./SDL.h"
#include "Camera.h"
#include "./Vector.h"

class Player {
  public:
  Player();
  Vector position;
  Vector speed;

  void decelerate();

  void draw(Camera * camera);
  void tick();
};
