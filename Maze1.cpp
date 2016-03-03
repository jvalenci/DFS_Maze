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
	d = DOWN;
	current = start;
	path.push(current);
	while (M[current.Neighbor(d).row][current.Neighbor(d).col] != OPEN || !validPosition(current.Neighbor(d))) {
		d = next_direction(d);
		if (d == NONE) {
			path.pop();
			return;
		}
	}
	current = current.Neighbor(d);

	while (!(current == exitpos)) {
		switch (M[current.row][current.col]) {
		case OPEN:
			d = DOWN;
			M[current.row][current.col] = VISITED;
			path.push(current);
			while (M[current.Neighbor(d).row][current.Neighbor(d).col] == WALL || M[current.Neighbor(d).row][current.Neighbor(d).col] == WALL || !validPosition(current.Neighbor(d))) {
				d = next_direction(d);
				if (d == NONE) {
					d = DOWN;
				}
			}
			current = current.Neighbor(d);
			break;
		case VISITED:
			if (path.size() > 0 && !(current == start)) {
				current = path.top();
				path.pop();
				break;
			}
			while (M[current.Neighbor(d).row][current.Neighbor(d).col] != OPEN || !validPosition(current.Neighbor(d))) {
				d = next_direction(d);
				if (d == NONE) {
					d = DOWN;
				}
			}
			current = current.Neighbor(d);
			break;
		case WALL:
			while (M[current.Neighbor(d).row][current.Neighbor(d).col] == WALL || !validPosition(current.Neighbor(d))) {
				d = next_direction(d);
				if (d == NONE) {
					d = DOWN;
				}
			}
			current = current.Neighbor(d);
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





