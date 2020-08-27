#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

class Point {
  sf::CircleShape shape;
public:
  Point();
  Point(sf::Vector2f position, float rad = 10, sf::Color color = sf::Color::Red);
  float distance(sf::Vector2f to);
  sf::Vector2f getPosition();
  void render(sf::RenderWindow* win);
};