#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close

  //    float desiredDistance = desiredMinimalDistance;
  //
  //    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
  //    if (!neighborhood.empty()) {
  //        Vector2f position = boid->transform.position;
  //        int countCloseFlockmates = 0;
  //        // todo: find and apply force only on the closest mates
  //    }

  Vector2f separatingForce = Vector2f::zero();
  int countCloseFlockmates = 0;
  Vector2f pos = Vector2f::zero();

  if(!neighborhood.empty())
  {
    pos = boid->getPosition();

    for (int i = 0; i < neighborhood.size(); ++i) {

      Vector2f neighborPos = neighborhood[i]->getPosition();
      auto diffVector = boid->getPosition() - neighborPos;
      auto distance = diffVector.getMagnitude();

      if(distance < desiredMinimalDistance)
      {
        auto hatVect = diffVector.normalized();
        separatingForce += hatVect/distance;
        countCloseFlockmates++;
      }
    }
    if(countCloseFlockmates != 0)
    {
      separatingForce /= countCloseFlockmates;
    }
  }
  separatingForce = Vector2f::normalized(separatingForce);

  return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
