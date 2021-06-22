#pragma once
#include "./SDL.h"
#include "./Player.h"
#include "./Camera.h"
#include "./Vector.h"
#include <iostream>

Player::Player(): position(0, 0), speed(0, 0) {};

/** Slows the player down to a stop */
void Player::decelerate() {
  this->speed = this->speed.setMangnitude( this->speed.getMagnitude() * 0.9 );
}

void Player::tick() {
  this->position = this->position.addVector(this->speed);
  std::cout << this->position.x << ", " << this->position.y << "\n";
}

void Player::draw(Camera * camera) {

  int x = std::round( this->position.x - camera->x );
  int y = std::round( this->position.y - camera->y );
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
