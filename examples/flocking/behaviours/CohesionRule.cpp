#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {

  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood

  Vector2f cohesionForce = {0, 0};
  Vector2f posSum = {0, 0};
  Vector2f PosCenter = {0,0};

  if (!neighborhood.empty())
  {
    for (int i = 0; i < neighborhood.size(); ++i) {
      posSum += neighborhood[i]->getPosition();
    }
    PosCenter = posSum / (neighborhood.size());
  }

  auto distVect = PosCenter - boid->getPosition();

  // find center of mass

  return distVect.normalized();
}