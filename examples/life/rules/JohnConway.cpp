#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
  for (int i = 0; i < world.SideSize() ; ++i)
  {
    for (int j = 0; j < world.SideSize() ; ++j)
    {

      auto currentCell = Point2D(i, j);
      int neighbors = CountNeighbors(world, currentCell);

      //if ( currentCell.Con() == 1 && neighbors < 2 || neighbors > 3) //checks if cell has too few neighbors and dies.
      {
        //dead();
      }

      //if ((currentCell.Con() == 1 && neighbors > 1) || (currentCell.Con() == 1 && neighbors < 4))  //checks if the cell is alive and has enough neighbors to live.
      {
        //live();
      }

      //if (currentCell.Con() == 0 && neighbors == 3) //checks if cell is dead but has enough neighbors to become alive.
      {
        //live();
      }
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  int cellNeighbors = 0;

  // probably a nested for loop checking the [8] neighbor positions around the current cell and returning # alive.
  // for(int i = 0; i < world.SideSize() ; ++i)  //sub out world.SideSize() for however you calc. the neighbor positions.
  {
    // for (int j = 0; j < world.SideSize() ; ++j)
    {
      // if ( CCN[i][j] == live)
      //{
      //   cellNeighbors++;
      // }
    }
  }
  // TODO: Question to Ask: Are we supposed to create more functionality outside of this file? (ie. live var for each point, etc)?

  return cellNeighbors;
}