#include "Agent.h"
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

std::vector<Point2D> Agent::generatePath(World* w) {
  // source cat
  //  destination exitPoint

  // camefrom, set of elements from frontier, queue frontier, visited;

  unordered_map<Point2D, Point2D> cameFrom;
  unordered_set<Point2D> frontierSet;
  queue<Point2D> frontier;
  unordered_map<Point2D, bool> visited;

  auto catPos = w->getCat();
  frontier.push(catPos);
  frontierSet.insert(catPos);
  Point2D exitPoint = Point2D(INT_MAX, INT_MAX);

  while (!frontier.empty()) {
    auto current = frontier.front();
    frontier.pop();
    frontierSet.erase(current);
    visited[current] = true;

    if(w->catWinsOnSpace(current))
    {
      exitPoint = current;
      break;
    }

    vector<Point2D> neighbors = w->neighbors(current);

    for (auto next : neighbors) {
      if (visited.contains(next) && !visited.at(next) && next != catPos && !w->getContent(next) && !frontierSet.contains(next) && next != exitPoint) {
        frontier.push(next);
        frontierSet.insert(next);
        cameFrom[next] = current;
      }

      //      if (next == cameFrom.end() && w->getContent(next) == 0) {
      //        frontier.push(next);
      //        cameFrom[(next.x, next.y)] = (current.x, current.y);
      //      }
    }
  }
  vector<Point2D> path;   // need to compile path form cameFrom and return path;

}
