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

	//default search direction.
	d = DOWN;

	//check first scenario where the start and end are in the same square
	if (start == exitpos)
	{
		return;
	}
	//move current down 
	current = current.Neighbor(d);

	//check to see if current is valid and that the state is open
	while (validPosition(current) && M[current.row][current.col] == OPEN ) {
		//check if current is at exit
		if (current == exitpos) {
			return;
		}

		//push onto path
		path.push(current);

		//mark visited
		M[current.row][current.col] = VISITED;

		//set current to next direction
		current = current.Neighbor(d = next_direction(d));
	}
	
	
}




