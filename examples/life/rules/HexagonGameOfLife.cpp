//
// Created by atolstenko on 2/9/2023.
//

#include "HexagonGameOfLife.h"
void HexagonGameOfLife::Step(World& world) {
  for (int y = 0; y < world.SideSize() ; y++) {
    for (int x = 0; x < world.SideSize(); x++) {
      int neighbors = CountNeighbors(world, {x, y});
      bool isAlive = world.Get({x, y});
      world.SetNext({x, y}, isAlive);

      if (isAlive) {
        if (neighbors <= 1 || neighbors >= 3) {
          world.SetNext({x, y}, false);
        }

        if (neighbors == 2)  // TODO: check if is needed
        {
          world.SetNext({x, y}, isAlive);
        }

      } else {
        if (neighbors == 2) {
          world.SetNext({x, y}, true);
        }
      }
    }
  }
}


int HexagonGameOfLife::CountNeighbors(World& world, Point2D point) {

  Point2D sideZero = {0, 0};
  Point2D sideOne =  {0, 0};
  Point2D sideTwo =  {0, 0};
  Point2D sideThree =  {0, 0};
  Point2D sideFour =  {0, 0};
  Point2D sideFive =  {0, 0};

  if (point.y % 2 == 0) {
   sideZero = {point.x - 1, point.y - 1};
   sideOne = {point.x , point.y - 1};
   sideTwo = {point.x + 1, point.y};
   sideThree = {point.x, point.y + 1};
   sideFour = {point.x - 1, point.y + 1};
   sideFive = {point.x - 1, point.y};
  }
  else
  {
     sideZero = {point.x, point.y - 1};
     sideOne = {point.x + 1, point.y - 1};
     sideTwo = {point.x + 1, point.y};
     sideThree = {point.x + 1, point.y + 1};
     sideFour = {point.x, point.y + 1};
     sideFive = {point.x - 1, point.y};
  }

  return world.Get(sideZero) + world.Get(sideOne) + world.Get(sideTwo) + world.Get(sideThree) + world.Get(sideFour) + world.Get(sideFive);
}