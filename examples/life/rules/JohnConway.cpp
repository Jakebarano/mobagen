#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {

  for (int y = 0; y < world.SideSize() ; ++y)
  {
    for (int x = 0; x < world.SideSize() ; ++x)
    {
      int neighbors = CountNeighbors(world, {x, y});

      if ( world.Get({x, y}) && (neighbors <= 1 || neighbors > 3)) //checks if cell has too few/many neighbors and dies.
      {
        world.SetNext({x, y}, false);
      }
      else if (world.Get({x, y}) && (neighbors == 2 || neighbors == 3))  //checks if the cell is alive and has enough neighbors to live.
      {
        world.SetNext({x, y}, true);
      }

      else if (!world.Get({x, y}) && neighbors == 3) //checks if cell is dead but has enough neighbors to become alive.
      {
        world.SetNext({x, y}, true);
      }
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  int cellNeighbors = 0;

  for(int y = point.y -1 ; y <= point.y + 1; y++)
  {
    for (int x = point.x - 1; x <= point.x + 1 ; x++)
    {
      if (x != 0 && y != 0 && world.Get({point.x + x, point.y + y}))
      {
        cellNeighbors++;
      }
    }
  }
  return cellNeighbors;
}