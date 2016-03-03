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
	direction d;

	current = start;
	path.push(current);



	while (!(current == exitpos)) {
		for (d = DOWN; d != NONE; d = next_direction(d)) {
			switch (M[current.row][current.col]) {
			case OPEN:
				break;
			case VISITED:
				break;
			case WALL:
				break;
			}
		}

		if (path.top() == start) {
			path.pop();
		}
		else {
			path.push(current);
		}
	}
}





