#ifndef AGENT_H
#define AGENT_H
#include "math/Point2D.h"
#include <vector>
#include "World.h"

class World;

class Agent {
public:
  explicit Agent() = default;
  ;
  virtual Point2D Move(World*) = 0;
  std::vector<Point2D> generatePath(World* w);

  std::vector<Point2D> visitableNeighbors(std::vector<Point2D> n);

};

#endif  // AGENT_H
