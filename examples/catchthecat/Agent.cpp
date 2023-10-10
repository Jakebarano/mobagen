#include "Agent.h"
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

std::vector<Point2D> Agent::generatePath(World* w)
{
//source cat
// destination border

//camefrom, set of elements from frontier, queue frontier, visited;

map<int, map<int, Point2D>> cameFrom;
unordered_set<Point2D> frontierSet;
queue<Point2D> frontier;

auto catPos = w->getCat();

}