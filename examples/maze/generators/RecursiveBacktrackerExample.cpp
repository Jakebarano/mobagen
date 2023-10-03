#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

using namespace std;

bool RecursiveBacktrackerExample::Step(World* w) {
  //TODO: YOUR CODE HERE

  Point2D start  = randomStartPoint(w); //can start as 0,0
  stack.push_back(start);
  while (!stack.empty()) {
    Point2D currentP = stack[stack.size()-1];
    stack.pop_back();

    if (w->GetNode(start).GetVisited())  //should check for availability of tiles for backtracking
    {
    }

    vector<Point2D> neighbors = getVisitables(w, currentP);

    for(auto nextP = neighbors.begin(); nextP != neighbors.end(); ++nextP) {

    }
  }

  return true;
}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  return visitables;
}
