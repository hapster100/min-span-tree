#pragma once

#include <SFML/Graphics.hpp>

class Path {
  sf::Vertex line[2];
public:
  Path(sf::Vector2f a, sf::Vector2f b, sf::Color color = sf::Color::Blue);
  void render(sf::RenderWindow* win);
};
