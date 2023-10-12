#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <map>

using namespace std;

Point2D Cat::Move(World* world) {

  auto path = generatePath(world);

  if (!path.empty())
  {
    return path[path.size() - 1];
  }
//  else {
//    auto rand = Random::Range(0, 5); //change out for
//    auto pos = world->getCat();
//
//    switch (rand) {
//      case 0:
//        return World::NE(pos);
//      case 1:
//        return World::NW(pos);
//      case 2:
//        return World::E(pos);
//      case 3:
//        return World::W(pos);
//      case 4:
//        return World::SW(pos);
//      case 5:
//        return World::SE(pos);
//      default:
//        throw "random out of range";
//    }
//  }
}
