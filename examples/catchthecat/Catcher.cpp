#include "Catcher.h"
#include "World.h"
#include <vector>
#include <unordered_set>

Point2D Catcher::Move(World* world) {

  auto path = generatePath(world);

  if (!path.empty())
  {
    return path[0];
  }
  else {

    auto pos = world->getCat();
    auto neighbors = world->neighbors(pos);
    std::unordered_set<Point2D> availableNeighbors (neighbors.begin(), neighbors.end());

    while(!availableNeighbors.empty())
    {
      for(auto next : neighbors)
      {
        if(world->getContent(next))
        {
          availableNeighbors.erase(next);
        }
      }

      auto rand = Random::Range(0, availableNeighbors.size()-1);

      for(auto it = availableNeighbors.begin(); it != availableNeighbors.end(); it++)
      {
        if (rand == 0)
        {
          return *it;
        }
        rand--;
      }
    }
  }
}
