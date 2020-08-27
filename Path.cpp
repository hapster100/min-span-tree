#include "Path.hpp"

Path::Path(sf::Vector2f start, sf::Vector2f end, sf::Color color) {
  line[0] = sf::Vertex(start, color);
  line[1] = sf::Vertex(end, color);
}

void Path::render(sf::RenderWindow* win) {
  win->draw(line, 2, sf::Lines);
}
