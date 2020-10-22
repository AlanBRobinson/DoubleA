#pragma once
#include "./SDL.h"
#include "./Player.h"
#include "./Camera.h"
#include <iostream>

Player::Player() {
  this->x = 10;
  this->y = 10;

  this->speedX = 0;
  this->speedY = 0;
};

/** Slows the player down to a stop */
void Player::decelerate() {
  if(this->speedX > 0) {
    this->speedX -= 1;
  } else if(this->speedX < 0) {
    this->speedX += 1;
  }
  if(this->speedY > 0) {
    this->speedY -= 1;
  } else if(this->speedY < 0) {
    this->speedY += 1;
  }
}

void Player::tick() {
  this->x += this->speedX;
  this->y += this->speedY;
  std::cout << this->x << ", " << this->y << "\n";
}

void Player::draw(Camera * camera) {
  auto x = this->x - camera->x;
  auto y = this->y - camera->y;
  // Draw body
  SDL_Rect bodyRect = {
      x,
      y,
      50,
      100
  };
  SDL_Rect headRect = {
    x + 15,
    y -20,
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
