#pragma once
#include "./SDL.h"
#include "Camera.h"

class Player {
  public:
  Player();
  int x;
  int y;

  void draw(Camera * camera);
};
