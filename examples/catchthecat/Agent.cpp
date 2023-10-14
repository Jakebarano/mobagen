#include "Agent.h"
#include "World.h"

using namespace std;

std::vector<Point2D> Agent::generatePath(World* w) {
  // source cat
  //  destination exitPoint\
  // camefrom, set of elements from frontier, queue frontier, visited;

  unordered_map<Point2D, Point2D> cameFrom;
  unordered_set<Point2D> frontierSet;
  queue<Point2D> frontier;
  unordered_map<Point2D, bool> visited;
  Point2D current;

  auto catPos = w->getCat();
  frontier.push(catPos);
  frontierSet.insert(catPos);
  Point2D exitPoint = Point2D(INT_MAX, INT_MAX);

  while (!frontier.empty() && exitPoint == Point2D(INT_MAX, INT_MAX))
  {
    current = frontier.front();
    frontier.pop();
    frontierSet.erase(current);
    visited[current] = true;

    const vector<Point2D> neighbors = w->neighbors(current);

    for (auto next : neighbors) {
      if (!visited[next] && next != catPos && !w->getContent(next) && !frontierSet.contains(next))
      {
        frontier.push(next);
        frontierSet.insert(next);
        cameFrom[next] = current;

        if(w->catWinsOnSpace(next))
        {
          exitPoint = next;
          break;
        }
      }
    }
  }

  if (exitPoint == Point2D(INT_MAX, INT_MAX)) {
    return {};  // Return an empty path
  }

  vector<Point2D> path;   //compile path form cameFrom and return it.

  current = exitPoint;

  while (current != catPos)
  {
    path.push_back(current);
    current = cameFrom[current];
  }
  return path;
}
