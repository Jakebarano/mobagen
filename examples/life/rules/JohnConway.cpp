#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {

  for (int y = 0; y < world.SideSize() ; y++)
  {
    for (int x = 0; x < world.SideSize() ; x++)
    {
      int neighbors = CountNeighbors(world, {x, y});
      bool isAlive = world.Get({x, y});
      world.SetNext({x,y}, isAlive);

      if (isAlive)
      {
        if (neighbors <= 1 || neighbors >= 4)
        {
          world.SetNext({x,y}, false);
        }

        /* if (neighbors == 2 || neighbors == 3) //This test case is unnecessary
        {
          world.SetNext({x,y}, isAlive);
        }*/
      }
      else
      {
        if (neighbors == 3)
        {
          world.SetNext({x, y}, true);
        }
      }
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  return world.Get(point.Up()) + world.Get(point.Up().Left()) + world.Get(point.Up().Right()) + world.Get(point.Left()) + world.Get(point.Right()) + world.Get(point.Down().Left()) + world.Get(point.Down())+ world.Get(point.Down().Right());
}