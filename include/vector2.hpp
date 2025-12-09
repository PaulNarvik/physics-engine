#pragma once
#include <iostream>

class Vector2 {
private:
  float x_;
  float y_;

public:
  // Constructeurs
  Vector2();
  Vector2(float x, float y);
  Vector2(const Vector2 &other);

  // Getters
  float getX() const;
  float getY() const;

  // Setters
  void setX(float x);
  void setY(float y);

  // Opérateurs arithmétiques
  Vector2 operator+(const Vector2 &other) const;
  Vector2 operator-(const Vector2 &other) const;
  Vector2 operator*(float scalar) const;
  Vector2 operator/(float scalar) const;
  Vector2 operator-() const;

  // Opérateurs d'assignation
  Vector2 &operator=(const Vector2 &other);
  Vector2 &operator+=(const Vector2 &other);
  Vector2 &operator-=(const Vector2 &other);
  Vector2 &operator*=(float scalar);
  Vector2 &operator/=(float scalar);

  // Opérateurs de comparaison
  bool operator==(const Vector2 &other) const;
  bool operator!=(const Vector2 &other) const;

  // Calculs
  float norm() const;
  float dot(const Vector2 &other) const;
};

// Affichage
std::ostream &operator<<(std::ostream &os, const Vector2 &v);
