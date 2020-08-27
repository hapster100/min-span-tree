#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "FindUnion.hpp"
#include "Point.hpp"
#include "Path.hpp"

float getDistance(sf::Vector2f a, sf::Vector2f b) {
  return std::sqrt(
    (a.x - b.x) * (a.x - b.x) +
    (a.y - b.y) * (a.y - b.y)
  );
}

std::vector<Path> buildPathes(std::vector<Point> points) {
  struct PointsDistance {
    int aIndex;
    int bIndex;
    float distance;
  };
  
  std::vector<Path> pathes = {};

  std::vector<PointsDistance> distances = {};
  for(int i = 0; i < points.size(); i++)
    for(int j = i + 1; j < points.size(); j++)
      distances.push_back({i, j, points[i].distance(points[j].getPosition())});

  std::sort(distances.begin(), distances.end(), [](PointsDistance a, PointsDistance b) {
    return a.distance < b.distance;
  });

  UnionFind uf(points.size());
  for(int i = 0; i < distances.size(); i++) {
    if(uf.components() < 2) break;
    PointsDistance current = distances[i];

    if(!uf.connected(current.aIndex, current.bIndex)) {
      uf.unify(current.aIndex, current.bIndex);
      
      pathes.push_back(Path(
        points[current.aIndex].getPosition(),
        points[current.bIndex].getPosition()
      ));
    }
  }
  
  return pathes;
}

int main() {

  sf::RenderWindow window(sf::VideoMode(500, 500), "Window");
  
  std::vector<Point> points = {};
  std::vector<Path> pathes = {};

  sf::Event event;

  while(window.isOpen()) {
    window.clear();

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        window.close();
    }

    for(Path p : pathes) {
      p.render(&window);
    }
    for(Point p : points) {
      p.render(&window);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (mousePosition.x > 0 && mousePosition.y > 0
        && mousePosition.x < window.getSize().x
        && mousePosition.y < window.getSize().y) {
        
        float rad = 5;

        bool createNew = true;
        for(auto point : points) {
          if(point.distance({(float)mousePosition.x, (float)mousePosition.y}) < rad*2) {
            createNew = false;
            break;
          }
        }

        if (createNew) {
          sf::Vector2f position = {(float)mousePosition.x, (float)mousePosition.y};
          points.push_back(Point(position, rad));
          pathes = buildPathes(points);
        }
      }


    }

    window.display();
  }

  return 0;
}