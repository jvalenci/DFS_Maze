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

	//copy the first position
	current = start;

	//set starting position as visited
	M[current.row][current.col] = VISITED;

	//start the stack with your starting position
	path.push(current);


	//check first scenario where the start and end are in the same square
	if (start == exitpos)
	{
		return;
	}


	//check to see if current = exitpos
	while (!(current == exitpos) ) {

		//default search direction.
		d = DOWN;

		//Validate your initial move 
		current = current.Neighbor(d);

		if (!validPosition(current) || M[current.row][current.col] == WALL) {
			current = current.Neighbor(UP);
			d = next_direction(d);
			current = current.Neighbor(d);
			if (!validPosition(current) || M[current.row][current.col] == WALL) {
				current = current.Neighbor(RIGHT);
				d = next_direction(d);
				current = current.Neighbor(d);
				if (!validPosition(current) || M[current.row][current.col] == WALL) {
					current = current.Neighbor(DOWN);
					d = next_direction(d);
					current = current.Neighbor(d);
					if (!validPosition(current) || M[current.row][current.col] == WALL) {
						current = path.top();
						path.pop();
					}
				}
			}
		}

		//d = DOWN;

		switch (M[current.row][current.col])
		{

		case OPEN:
			//check if current is at exit
			if (current == exitpos) {
				path.push(current);
				return;
			}

			switch (d)
			{

			case DOWN:
				current = current.Neighbor(DOWN);
				break;
			case LEFT:
				current = current.Neighbor(LEFT);
				break;
			case UP:
				current = current.Neighbor(UP);
				break;
			case RIGHT:
				current = current.Neighbor(RIGHT);
				break;
			default:
				break;
			}


			M[current.row][current.col] = VISITED;
			path.push(current);

			////set current to next down position 
			//current = current.Neighbor(d);

			break;

		default:
			current = path.top();
			path.pop();
			break;

		}
	}	
}





