#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();

  // todo: add your code here to align each boid in a neighborhood
  // hint: iterate over the neighborhood

  Vector2f velocitySum;

  if (!neighborhood.empty()) {
    for (int i = 0; i < neighborhood.size(); ++i) {
      velocitySum += neighborhood[i]->getVelocity();
    }

    averageVelocity.x = velocitySum.x / neighborhood.size();
    averageVelocity.y = velocitySum.y / neighborhood.size();

  }

  return Vector2f::normalized(averageVelocity);
}