#include <vector2.hpp>

// Constructeurs
Vector2::Vector2() : x_(0.0f), y_(0.0f) {};
Vector2::Vector2(float x, float y) : x_(x), y_(y) {};
Vector2::Vector2(const Vector2 &other) : x_(other.x_), y_(other.y_) {};

// Opérateurs arithmétiques
Vector2 Vector2::operator+(const Vector2 &other) const {
  return Vector2(x_ + other.x_, y_ + other.y_);
}
Vector2 Vector2::operator-(const Vector2 &other) const {
  return Vector2(x_ - other.x_, y_ - other.y_);
}
Vector2 Vector2::operator*(float scalar) const {
  return Vector2(x_ * scalar, y_ * scalar);
}
Vector2 Vector2::operator/(float scalar) const {
  if (scalar == 0.0f)
    return Vector2(0, 0);
  return Vector2(x_ / scalar, y_ / scalar);
}
Vector2 Vector2::operator-() const { return Vector2(-x_, -y_); }

// Getters
float Vector2::getX() const { return x_; }
float Vector2::getY() const { return y_; }

// Setters
void Vector2::setX(float x) { x_ = x; }
void Vector2::setY(float y) { y_ = y; }

// Opérateurs d'assignation
Vector2 &Vector2::operator=(const Vector2 &other) {
  x_ = other.x_;
  y_ = other.y_;
  return *this;
}
Vector2 &Vector2::operator+=(const Vector2 &other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}
Vector2 &Vector2::operator-=(const Vector2 &other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}
Vector2 &Vector2::operator*=(float scalar) {
  x_ *= scalar;
  y_ *= scalar;
  return *this;
}
Vector2 &Vector2::operator/=(float scalar) {
  if (scalar != 0.0f) {
    x_ /= scalar;
    y_ /= scalar;
  }
  return *this;
}

// Opérateurs de comparaison
bool Vector2::operator==(const Vector2 &other) const {
  return x_ == other.x_ && y_ == other.y_;
}
bool Vector2::operator!=(const Vector2 &other) const {
  return x_ != other.x_ || y_ != other.y_;
}

// Calculs
float Vector2::norm() const { return x_ * x_ + y_ * y_; }
float Vector2::dot(const Vector2 &other) const {
  return x_ * other.x_ + y_ * other.y_;
}

// Affichage
std::ostream &operator<<(std::ostream &os, const Vector2 &v) {
  os << "(" << v.getX() << ", " << v.getY() << ")";
  return os;
}
