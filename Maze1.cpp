#include "Maze1.h"
#include <iostream>
#include <cassert>
#include <conio.h>

using namespace std;

Maze1::~Maze1()
{
  // FILL IN THE CODE FOR THIS METHOD

}

void Maze1::find_exit()
// Use the DFS method to fill the path stack with the exit path Positions
// If there is no path to the exit, then after execution of this function
// the stack path should be empty
// This function does no input and no output
{
	// FILL IN THE CODE FOR THIS METHOD
	Position nbr, current;
	direction d = DOWN;

	current = start;

	while (!(current == exitpos)) {
		switch (M[current.row][current.col]) {
		case OPEN:
			M[current.row][current.col] = VISITED;
			path.push(current);
			current = current.Neighbor(d);
			break;
		case VISITED:
			if (current == path.top()) {
				path.pop();
			}
			d = next_direction(d);
			current.Neighbor(d);
			break;
		case WALL:
			break;
		}
	}
	
}





