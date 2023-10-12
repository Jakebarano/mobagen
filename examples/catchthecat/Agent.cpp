#include "Agent.h"
#include "World.h"

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
  Point2D current;

  while (!frontier.empty() && exitPoint == Point2D(INT_MAX, INT_MAX)) {
    cout << frontier.size() << "\n";
    current = frontier.front();
    frontier.pop();
    frontierSet.erase(current);
    visited[current] = true;

    vector<Point2D> neighbors = visitableNeighbors(current, w, frontierSet, visited);

    for (auto next : neighbors) {
      cameFrom[next] = current;
      frontier.push(next);
      frontierSet.insert(next);

      if(w->catWinsOnSpace(next))
      {
        exitPoint = next;
        break;
      }
    }
  }
  vector<Point2D> path;   // need to compile path form cameFrom and return path;

  current = exitPoint;

  while (current != catPos)
  {
    path.push_back(current);
    current = cameFrom[current];
  }
  return path;
}

std::vector<Point2D> Agent::visitableNeighbors(Point2D p, World* w, const unordered_set<Point2D>& frontierSet,unordered_map<Point2D, bool>& visited)
{
  std::vector<Point2D> neighbors;

  auto NE = World::NE(p);
  auto NW = World::NW(p);
  auto E = World::E(p);
  auto W = World::W(p);
  auto SW = World::SW(p);
  auto SE = World::SE(p);

  auto cat = w->getCat();

  /*
   * 1. is not the visited, check visited map
   * 2. is not the cat, check get cat pos
   * 3. is not the blocks, check get content of world
   * 4. is not in the queue (frontier set) : check set
   */

  if(visited[NE] == false && NE != cat && w->getContent(NE) == false && !frontierSet.contains(NE))
  {
    neighbors.push_back(World::NE(p));
  }

  if(visited[NW] == false && NW != cat && w->getContent(NW) == false && !frontierSet.contains(NW))
  {
    neighbors.push_back(World::NW(p));
  }

  if(visited[E] == false && E != cat && w->getContent(E) == false && !frontierSet.contains(E))
  {
    neighbors.push_back(World::E(p));
  }

  if(visited[W] == false && W != cat && w->getContent(W) == false && !frontierSet.contains(W))
  {
    neighbors.push_back(World::W(p));
  }

  if(visited[SW] == false && SW != cat && w->getContent(SW) == false && !frontierSet.contains(SW))
  {
    neighbors.push_back(World::SW(p));
  }

  if(visited[SE] == false && SE != cat && w->getContent(SE) == false && !frontierSet.contains(SE))
  {
    neighbors.push_back(World::SE(p));
  }

  return neighbors;

}
