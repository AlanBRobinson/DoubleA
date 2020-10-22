#pragma once
#include "./SDL.h"
#include "Camera.h"

class Player {
  public:
  Player();
  int x;
  int y;
  int speedX;
  int speedY;

  void decelerate();

  void draw(Camera * camera);
  void tick();
};
