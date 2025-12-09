#include "circle.hpp"
#include "constants.hpp"
#include "vector2.hpp"

// Constructeurs
Circle::Circle()
    : position_(Vector2()), oldPosition_(Vector2()), velocity_(Vector2()),
      acceleration_(Vector2()), forces_(Vector2()), radius_(50.0f), mass_(1.0f),
      color_(255) {};
Circle::Circle(float x, float y, float vx, float vy, float radius, float mass,
               Uint8 color)
    : position_(Vector2(x, y)), oldPosition_(Vector2(x, y)),
      velocity_(Vector2(vx, vy)), acceleration_(Vector2(0.0f, 0.0f)),
      forces_(Vector2(0.0f, 0.0f)), radius_(radius), mass_(mass),
      color_(color) {};
Circle::Circle(const Circle &other)
    : position_(other.position_), oldPosition_(other.oldPosition_),
      velocity_(other.velocity_), acceleration_(other.acceleration_),
      forces_(Vector2(0.0f, 0.0f)), radius_(other.radius_), mass_(other.mass_),
      color_(other.color_) {};

// Gestion des forces
void Circle::addForce(Vector2 force) { forces_ += force; }
void Circle::clearForces() {
  forces_.setX(0.0f);
  forces_.setY(0.0f);
}

void Circle::update(float dt) {
  addForce(Vector2(0, 500));
  acceleration_ = forces_ / mass_;
  clearForces();
  velocity_ += acceleration_ * dt;
  position_ += velocity_ * dt;
  // Vector2 newPosition =
  //     position_ * 2.0f - oldPosition_ + acceleration_ * dt * dt;
  //
  // oldPosition_ = position_;
  // position_ = newPosition;

  float x = position_.getX();
  float y = position_.getY();
  float vx = velocity_.getX();
  float vy = velocity_.getY();

  if ((x - radius_ < 0 && vx <= 0) || (x + radius_ > WINDOW_WIDTH && vx >= 0)) {
    velocity_.setX(-vx * ENERGY_LOSS_COEFF);
  }
  if ((y - radius_ < 0 && vy <= 0) ||
      (y + radius_ > WINDOW_HEIGHT && vy >= 0)) {
    velocity_.setY(-vy * ENERGY_LOSS_COEFF);
  }
}

void Circle::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color_, color_, color_, Uint8(1));

  // Algorithme de cercle simple (midpoint circle algorithm)
  float x = position_.getX();
  float y = position_.getY();

  float dx = radius_;
  float dy = 0;
  float err = 0;

  while (dx >= dy) {
    SDL_RenderLine(renderer, x - dy, y + dx, x + dy, y + dx);
    SDL_RenderLine(renderer, x - dx, y + dy, x + dx, y + dy);
    SDL_RenderLine(renderer, x - dx, y - dy, x + dx, y - dy);
    SDL_RenderLine(renderer, x - dy, y - dx, x + dy, y - dx);

    if (err <= 0) {
      dy += 1;
      err += 2 * dy + 1;
    }
    if (err > 0) {
      dx -= 1;
      err -= 2 * dx + 1;
    }
  }
}
