#include "BoundedAreaRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f BoundedAreaRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Return a force proportional to the proximity of the boids with the bounds, and opposed to it
  Vector2f force = Vector2f::zero();  // zero

  //float REVERSEVELOCITY = 1.0f;
  // todo: add here your code here do make the boid follow the bounded box rule
  // hint: use this->world->engine->window->size() and desiredDistance

  Vector2f boundsDiff = Vector2f(desiredDistance, desiredDistance);

  Vector2f windowSize = Vector2f(this->world->engine->window->size().x, this->world->engine->window->size().y);

  Vector2f  boundedArea = windowSize - boundsDiff;

  if(boid->getPosition().x > boundedArea.x)
  {
    boid->setVelocity(boid->getVelocity() *= -1.0);

    // reverses the velocity if the positions on the Axis are greater than the area.
    // this approach has issue with boids at edge since the bounds starts at 20, leads to issues with the flocks as well.

  }
  else if (boid->getPosition().y > boundedArea.y)
  {
    boid->setVelocity(boid->getVelocity() *= -1.0);
  }

  return boid->getVelocity();
}

bool BoundedAreaRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  auto size = this->world->engine->window->size();
  auto widthWindows = size.x;
  auto heightWindows = size.y;
  bool valueHasChanged = false;

  // We cap the max separation as the third of the min of the width.height
  auto minHeightWidth = std::min(widthWindows, heightWindows);

  if (ImGui::SliderInt("Desired Distance From Borders", &desiredDistance, 0.0f, (int)(minHeightWidth / 3), "%i")) {
    valueHasChanged = true;
  }

  return valueHasChanged;
}

void BoundedAreaRule::draw(const Boid& boid, SDL_Renderer* renderer) const {
  FlockingRule::draw(boid, renderer);
  auto size = this->world->engine->window->size();
  auto dist = (float)desiredDistance;

  // Draw a rectangle on the map
  Polygon::DrawLine(renderer, Vector2f(dist, dist), Vector2f(size.x - dist, dist), Color::Gray);                    // TOP
  Polygon::DrawLine(renderer, Vector2f(size.x - dist, dist), Vector2f(size.x - dist, size.y - dist), Color::Gray);  // RIGHT
  Polygon::DrawLine(renderer, Vector2f(size.x - dist, size.y - dist), Vector2f(dist, size.y - dist), Color::Gray);  // Bottom
  Polygon::DrawLine(renderer, Vector2f(dist, size.y - dist), Vector2f(dist, dist), Color::Gray);                    // LEFT
}