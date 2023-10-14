#include "Catcher.h"
#include "World.h"
#include <vector>
Point2D Catcher::Move(World* world) {

  auto path = generatePath(world);

  if (!path.empty())
  {
    return path[0];
  }
  else {
        auto rand = Random::Range(0, 5); //change out for
        auto pos = world->getCat();

        std::vector<Point2D> neighbors = world->neighbors(pos);
          switch (rand) {
            case 0:
              if (!world->getContent(World::NE(pos)) && world->isValidPosition(World::NE(pos))) {
                return World::NE(pos);
              }
              break;
            case 1:
              if (!world->getContent(World::NW(pos)) && world->isValidPosition(World::NW(pos))) {
                return World::NW(pos);
              }
              break;
            case 2:
              if (!world->getContent(World::E(pos)) && world->isValidPosition(World::E(pos))) {
                return World::E(pos);
              }
              break;
            case 3:
              if (!world->getContent(World::W(pos)) && world->isValidPosition(World::W(pos))) {
                return World::W(pos);
              }
              break;
            case 4:
              if (!world->getContent(World::SW(pos)) && world->isValidPosition(World::SE(pos))) {
                return World::SW(pos);
              }
              break;
            case 5:
              if (!world->getContent(World::SE(pos)) && world->isValidPosition(World::SE(pos))) {
                return World::SE(pos);
              }
              break;
          }
//    auto side = world->getWorldSideSize() / 2;
//    for (;;) {
//      Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
//      auto cat = world->getCat();
//      if (cat.x != p.x && cat.y != p.y && !world->getContent(p) && world->isValidPosition(p)) return p;
//    }
  }
}
