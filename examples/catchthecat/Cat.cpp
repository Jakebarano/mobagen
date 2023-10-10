#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <map>

using namespace std;

Point2D Cat::Move(World* world) {
  auto rand = Random::Range(0, 5); //change out for
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
  }

queue<Point2D> frontier;

frontier.push(world->getCat());
map came_from = dict() # path A->B is stored as came_from[B] == A
came_from[start] = None

while not frontier.empty():
 current = frontier.get()
 for next in graph.neighbors(current):
    if next not in came_from:
       frontier.put(next)
       came_from[next] = current

}
