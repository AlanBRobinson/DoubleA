#pragma once
#include "./SDL.h"

class Camera {
  public:
  /** Camera's centre X coordinate */
  int x = 0;
  /** Camera's centre Y coordinate */
  int y = 0;
  SDL_Surface * surface;

  Camera(SDL_Surface * surface);
};
