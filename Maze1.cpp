#include "Maze1.h"
#include <iostream>
#include <cassert>

using namespace std;

void depthSearch(Position pos);

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

	M[start.row][start.col] = VISITED;
	path.push(start);

	if (start == exitpos) {
		return;
	}

	current = start;
	current = current.Neighbor(d);

	for (int i = 0; i < size * size; ++i) {

		if (current == exitpos) {
			return;
		}

		if (validPosition(current) && M[current.row][current.col] == OPEN) {
			d = DOWN;
			path.push(current);
			M[current.row][current.col] = VISITED;
			while (!validPosition(current.Neighbor(d))) {
				d = next_direction(d);
			}
			current = current.Neighbor(d);
		}
		else if (validPosition(current) && M[current.row][current.col] == WALL) {
			current = path.top();
			//d = next_direction(d);
			while (!validPosition(current.Neighbor(d)) && M[current.Neighbor(d).row][current.Neighbor(d).col] != VISITED) {
				d = next_direction(d);
				current = current.Neighbor(d);
			}
		}
		else if (validPosition(current) && M[current.row][current.col] == VISITED) {
			
			//while (M[current.row][current.col] == VISITED) {
				for (direction i = DOWN; i != NONE; i = next_direction(i)) {
					if (M[current.Neighbor(i).row][current.Neighbor(i).col] == OPEN) {
						current = current.Neighbor(i);
						break;
					}
				}
				if (M[current.row][current.col] == VISITED) {
					current = path.top();
					path.pop();
					d = next_direction(d);
				}
			//}
			
		}
	}		
}









