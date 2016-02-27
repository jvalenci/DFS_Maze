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

	while (!validPosition(start.Neighbor(d))) {
		d = next_direction(d);
	}
	current = start.Neighbor(d);

	while (!path.empty()) {

		if (current == exitpos) {
			return;
		}

		switch (M[current.row][current.col]) {
		
		case OPEN:

			//M[current.row][current.col] = VISITED;
			for (; ;) {
				if (M[current.row][current.col] == VISITED) {
					break;
				}
				for (direction i = DOWN; i != NONE; i = next_direction(i)) {
					if (validPosition(current.Neighbor(i)) &&  M[current.Neighbor(i).row][current.Neighbor(i).col] == OPEN) {
						//M[current.row][current.col] = VISITED;
						current = current.Neighbor(i);
						M[current.row][current.col] = VISITED;
						path.push(current);
						
					}
				}
			}
			break;

		case VISITED:

			path.pop();
			current = path.top();

			break;
		
		case WALL:

			current = path.top();
			
			break;
		}

	}		
}









