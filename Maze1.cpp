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
	int count = 0;
	
	//initi the starting position
	current = start;
	path.push(current);
	if (current == exitpos)
	{
		return;
	}
	M[current.row][current.col] = VISITED;
	for (direction dir = DOWN; dir != NONE; dir = next_direction(dir)) {
		if (M[current.Neighbor(dir).row][current.Neighbor(dir).col] != OPEN) {
			++count;
		}
	}
	if (count >= 4) {
		path.pop();
		return;
	}
	count = 0;
	while (!(current == exitpos)) {
		
		//validate before starting switch
		while (!validPosition(current.Neighbor(d)) || current.Neighbor(d) == NULLPOS ) {
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
			++count;
			if (count >= size * size) {
				for (int i = 0; i < path.size(); ++i) {
					path.pop();
				}
			}

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
				try {
					path.pop();
				}
				catch (exception e) {
					return;
				}
				current = path.top();
				d = DOWN;
			}

			break;

		default:
			current = path.top();
			if (d == NONE) {
				d = DOWN;
			}
			else {
				d = next_direction(d);
			}
		}
	}
}





