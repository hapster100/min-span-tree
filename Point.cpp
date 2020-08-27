#include "./Point.hpp"

Point::Point() : Point({0, 0}) {}
Point::Point(sf::Vector2f position, float rad, sf::Color color) {
  shape.setFillColor(color);
  shape.setPosition(position);
  shape.setOrigin({rad, rad});
  shape.setRadius(rad);
}

float Point::distance(sf::Vector2f to) {
  sf::Vector2f pos = shape.getPosition();
  return std::sqrt(std::pow(pos.x - to.x, 2) + std::pow(pos.y -to.y, 2));
}

sf::Vector2f Point::getPosition() {
  return shape.getPosition();
}

void Point::render(sf::RenderWindow* win) {
  win->draw(shape);
}

