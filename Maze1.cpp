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
	
	//initi the starting position
	current = start;
	path.push(current);
	M[current.row][current.col] = VISITED;

	
	while (!(current == exitpos)) {
		
		//validate before starting switch
		while (!validPosition(current.Neighbor(d)) && M[current.Neighbor(d).row][current.Neighbor(d).col] != WALL) {
			if (d == NONE) {
				d = DOWN;
			}
			d = next_direction(d);
		}
		current = current.Neighbor(d);
		
		switch (M[current.row][current.col]) {
		case OPEN:
			d = DOWN;
			path.push(current);
			M[current.row][current.col] = VISITED;
			break;
		case VISITED:
			nbr = path.top();
			for (direction dir = DOWN; dir != NONE; dir = next_direction(dir)) {
				if (M[nbr.Neighbor(dir).row][nbr.Neighbor(dir).col] == OPEN) {
					current = nbr.Neighbor(dir);
					break;
				}
			}
			if(path.size() > 0)
				path.pop();
			break;
		case WALL:
			break;
		}
	}

	

}





