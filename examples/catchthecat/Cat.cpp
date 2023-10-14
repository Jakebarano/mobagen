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

//    auto rand = Random::Range(0, 5); //change out for
//
//    switch (rand) {
//      case 0:
//        if (!world->getContent(World::NE(pos))) {
//          return World::NE(pos);
//        }
//        break;
//      case 1:
//        if (!world->getContent(World::NW(pos))) {
//          return World::NW(pos);
//        }
//        break;
//      case 2:
//        if (!world->getContent(World::E(pos))) {
//          return World::E(pos);
//        }
//        break;
//      case 3:
//        if (!world->getContent(World::W(pos))) {
//          return World::W(pos);
//        }
//        break;
//      case 4:
//        if (!world->getContent(World::SW(pos))) {
//          return World::SW(pos);
//        }
//        break;
//      case 5:
//        if (!world->getContent(World::SE(pos))){
//          return World::SE(pos);
//        }
//        break;
//      default:
//        return World::NE(pos);
//    }
  }
}
