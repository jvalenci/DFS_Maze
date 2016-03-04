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
	bool flag;
	
	//initi the starting position
	current = start;
	path.push(current);
	M[current.row][current.col] = VISITED;

	
	while (!(current == exitpos)) {
		
		//validate before starting switch
		while (!validPosition(current.Neighbor(d)) /*&& M[current.Neighbor(d).row][current.Neighbor(d).col] != WALL*/) {
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
			flag = true;
			nbr = path.top();
			if (true) {
				for (d = DOWN; d != NONE; d = next_direction(d)) {
					if (M[nbr.Neighbor(d).row][nbr.Neighbor(d).col] == OPEN) {
						current = nbr;
						flag = false;
						break;
					}
				}
			}
			if (path.size() > 0 && flag) {
				path.pop();
				current = nbr;
				d = DOWN;
			}

			break;
		case WALL:
			break;

		default:
			current = path.top();

		}
	}

	

}





