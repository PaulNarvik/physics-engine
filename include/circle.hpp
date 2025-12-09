#pragma once

#include "vector2.hpp"
#include <SDL3/SDL.h>

class Circle {
private:
  Vector2 position_;
  Vector2 oldPosition_;
  Vector2 velocity_;
  Vector2 acceleration_;
  Vector2 forces_;

  float radius_;
  float mass_;
  Uint8 color_;

public:
  // Constructeurs
  Circle();
  Circle(float x, float y, float vx, float vy, float radius, float mass,
         Uint8 color);
  Circle(const Circle &other);

  // Gestion des forces
  void addForce(Vector2 force);
  void clearForces();

  void update(float dt);

  void draw(SDL_Renderer *renderer);
};
