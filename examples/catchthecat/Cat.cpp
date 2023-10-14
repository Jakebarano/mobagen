#include "Cat.h"
#include "World.h"
#include <stdexcept>


using namespace std;

Point2D Cat::Move(World* world) {

  auto path = generatePath(world);


  if (!path.empty())
  {
    return path[path.size() - 1];
  }
  else {
    auto pos = world->getCat();
    auto neighbors = world->neighbors(pos);
    unordered_set<Point2D> availableNeighbors (neighbors.begin(), neighbors.end());

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
