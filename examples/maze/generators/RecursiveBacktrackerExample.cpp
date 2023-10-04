#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

using namespace std;

bool RecursiveBacktrackerExample::Step(World* w) {
  // TODO: YOUR CODE HERE
  auto start = randomStartPoint(w);

  if (stack.empty() && start == Point2D{INT_MAX, INT_MAX}) {
    return false;
  }

  if (stack.empty())
  {
    stack.push_back(start);
    return true;
  }

  Point2D currentP = stack[stack.size() - 1];
    visited[currentP.x][currentP.y] = true;
    w->SetNodeColor(currentP, Color::Yellow);

  auto neighbors = getVisitables(w, currentP);

  if(neighbors.empty())
  {
    stack.pop_back();
    w->SetNodeColor(currentP, Color::Black);
    return true;
  }
  else if (neighbors.size() == 1)
  {
    //no need for random
    breakWall(w, currentP, neighbors[0]);
    stack.push_back(neighbors[0]);
    visited[neighbors[0].x][neighbors[0].y] = true;
    w->SetNodeColor(neighbors[0], Color::Tomato);
    return true;
  }
  else if (neighbors.size() > 1)
  {
    int randChoice = Random::Range(0, neighbors.size()-1);
    breakWall(w, currentP, neighbors[randChoice]);
    stack.push_back(neighbors[randChoice]);
    visited[neighbors[randChoice].x][neighbors[randChoice].y] = true;
    w->SetNodeColor(neighbors[randChoice], Color::Tomato);
    return true;
  }
  // for(auto nextP = neighbors.begin(); nextP != neighbors.end(); ++nextP) {
  //
  // }
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

void RecursiveBacktrackerExample::breakWall(World* w, Point2D origin, Point2D target)
{
  auto delta = target - origin;
  if (delta.y <= -1)
  {
    w->SetNorth(origin.Up(), false);
  }
  if(delta.y >= 1)
  {
    w->SetSouth(origin.Down(), false);
  }
  if (delta.x <= -1)
  {
    w->SetWest(origin.Left(), false);
  }
  if (delta.x >= 1)
  {
    w->SetEast(origin.Right(), false);
  }
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  if(p.y > -sideOver2 && !visited[p.x][p.y - 1])
  {
    visitables.push_back(p.Up());
  }
  if(p.y <= sideOver2 && !visited[p.x][p.y + 1])
  {
    visitables.push_back(p.Down());
  }
  if(p.x <= sideOver2 && !visited[p.x + 1][p.y])
  {
    visitables.push_back(p.Right());
  }
  if(p.x > -sideOver2 && !visited[p.x - 1][p.y])
  {
    visitables.push_back(p.Left());
  }
  return visitables;
}