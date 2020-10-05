#pragma once
#include "./SDL.h"
#include "./Player.h"
#include "./Camera.h"
#include <iostream>

Player::Player() {
  this->x = 10;
  this->y = 10;
};

void Player::draw(Camera * camera) {
  auto x = this->x - camera->x;
  auto y = this->y - camera->y;
  std::cout << "Draw " << x << ", " << y << "\n";
  // Draw body
  SDL_Rect bodyRect = {
      x,
      y,
      50,
      100
  };
  SDL_Rect headRect = {
    x,
    y -100,
    20,
    20
  };
  SDL_FillRect( 
    camera->surface,
    &bodyRect,
    SDL_MapRGB( camera->surface->format, 255, 100, 100 )
  );
  // Draw head
  SDL_FillRect( 
    camera->surface,
    &headRect,
    SDL_MapRGB( camera->surface->format, 100, 255, 100 )
  );
};
