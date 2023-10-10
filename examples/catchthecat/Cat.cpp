#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <map>

using namespace std;

Point2D Cat::Move(World* world) {
  /*auto rand = Random::Range(0, 5); //change out for
  auto pos = world->getCat();

  switch (rand) {
    case 0:
      return World::NE(pos);
    case 1:
      return World::NW(pos);
    case 2:
      return World::E(pos);
    case 3:
      return World::W(pos);
    case 4:
      return World::SW(pos);
    case 5:
      return World::SE(pos);
    default:
      throw "random out of range";
  }*/

  queue<Point2D> frontier;

  frontier.push(world->getCat());
  // map came_from = dict() # path A->B is stored as came_from[B] == A
  //  Dictionary to store the mapping from nodes to their predecessors

  map<int, int> came_from;

  // came_from[(world->getCat().x, world->getCat().y)] = -1;

  while (!frontier.empty()) {
    Point2D current = frontier.front();
    frontier.pop();

    if (world->catWinsOnSpace(current)) {
      break;
    }

    vector<Point2D> neighbors = world->neighbors(current);

    for (auto next : neighbors) {
      if (came_from.find((next.x, next.y)) == came_from.end() && world->getContent(next) == 0) {
        frontier.push(next);
        came_from[(next.x, next.y)] = (current.x, current.y);
      }
    }
  }
}
