#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

using namespace std;

Color32 white(0,0,0,255);
Color32 red(255,0,0,255);

bool RecursiveBacktrackerExample::Step(World* w) {
  //TODO: YOUR CODE HERE

  if (stack.empty()) {
    Point2D start = randomStartPoint(w);  // can start as 0,0
    stack.push_back(start);
  }

    Point2D currentP = stack[stack.size()-1];
    stack.pop_back();

    if (!w->GetNode(currentP).GetVisited())  //should check for availability of tiles for backtracking
    {
      visited[currentP.x][currentP.y] = true;
      w->GetNode(currentP).SetVisit(true);
      w->SetNodeColor(currentP, red);
    }

    vector<Point2D> neighbors = getVisitables(w, currentP);



    //for(auto nextP = neighbors.begin(); nextP != neighbors.end(); ++nextP) {
    //
    //}

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

  if(w->GetNorth(p))
  {
    visitables.push_back(p.Up());
  }
  if(w->GetSouth(p))
  {
    visitables.push_back(p.Down());
  }
  if(w->GetEast(p))
  {
    visitables.push_back(p.Right());
  }
  if(w->GetWest(p))
  {
    visitables.push_back(p.Left());
  }

  return visitables;
}
