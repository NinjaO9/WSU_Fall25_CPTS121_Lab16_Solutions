#include "Lab13.h"
/* Doesn't actually change string, just prints in reverse */
void reverseString(char* c)
{
	if (*c == '\0')
		return;
	reverseString((c + 1));
	printf("%c", *c);
}

/* Reverses string */
void reverseStringTwo(char string[], int start, int end)
{
	if (start >= end)
		return;

	char temp = string[start];
	string[start] = string[end];
	string[end] = temp;

	reverseStringTwo(string, start + 1, end - 1);
}

int sumOfDigits(int num)
{
	if (num == 0)
		return num;
	return (num % 10) + (sumOfDigits(num / 10));
}

void printMaze(char board[][MAZE_SIZE])
{
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", board[r][c]);
		}
		printf("\n");
	}
}


int traverseMaze(char board[][MAZE_SIZE], int col, int row)
{
	//printf("Maze stats: %d %d\n", x, y);
	//printMaze(board);
	if (row < 0 || col < 0 || col >= MAZE_SIZE || row >= MAZE_SIZE) // Check for a valid array index to prevent runtime errors
		return 0;

	if (board[col][row] == WALL || board[col][row] == TRAVEL_MARKER) // Check for a border (invalid move space) or for a space we already traveled on before (prevent infinite loops)
	{
		return 0;
	}
	if (col == GOAL_COORD && row == GOAL_COORD) // Check for goal
	{
		board[col][row] = TRAVEL_MARKER;
		return 1;
	}
	// The above if statements are our base cases, if none of those are true, we can move forward to checking each direction:
	board[col][row] = TRAVEL_MARKER; // Leave a trail of where we have gone

	// Check each direction. We will only get a 'true' condition if one of these functions leads us to the goal
	if (traverseMaze(board, col, row + 1)) // right
	{
		return 1;
	}
	if (traverseMaze(board, col, row - 1)) // left
	{
		return 1;
	}
	if (traverseMaze(board, col + 1, row)) // up
	{
		return 1;
	}
	if (traverseMaze(board, col - 1, row)) // down
	{
		return 1;
	}
	//board[x][y] = ' ';
	return 0; // If none of the directions work, return 0 so we can trace back to the next decision.
}

void towersofHanoi(int disk, char source, char aux, char dest)
{
	// Base case, if we only have one disk, all we have to do to put it in the correct spot is to simply place it there
	if (disk == 1)
	{
		printf("Move disk from %c to %c\n", source, dest);
		return;
	}
	towersofHanoi(disk - 1, source, dest, aux);
	printf("Move disk from %c to %c\n", source, dest);
	towersofHanoi(disk - 1, aux, source, dest);
}

/*
* So this was a little weird to think about, but I will try to explain it:
* 
*	First lets look at the case of 1:
*		|     |     |
*		|     |     |
*       -     |     |
* 
*	Obvoiusly, if we want to move all the disks from peg 1 to peg 3, we need to simply move the disk to the third peg, and we are done
*	Order goes:
*	Peg A -> Peg C
* 
*	Keep in mind that I mentioned very briefly that to find the least ammount of moves needed in towers of hanoi given n disks, the equation is: 2^n - 1
*	2^1 - 1 = 1, so the case here holds (obviously)
* 
*	Now, we will look at a case of 2:
*		|     |     |
*		-     |     |
*      ---    |     |
* 
*	Now it is a little different. Remember we want to most efficient path to get all the disks from peg A to peg C. Thus, we have to use the auxillery peg 
	to allow the largest disk to be placed on peg C first. Then, we can move the smaller disk from peg B to peg C.
*	Order goes:
*	Peg A -> Peg B
*	Peg A -> Peg C
*	Peg B -> Peg C
*	2^2 - 1 = 3, which supports this algorithm
*
*	We will think of this in the case of 3:
*		-    
*	   ---     |     |
*     -----    |     |
*	
*	Now it gets more tricky, where we have to grab the first disk, place it in peg C, then the next disk, place it in peg B. So our current setup looks like:
*		|     |     |
*		|     |     |
*     -----  ---    -
*	Now, we move the smallest disk from peg C to peg B, the largest disk from peg A to peg C, move the smallest disk from peg B to peg A, medium disk from peg B to peg C, then the smallest from peg A to peg C
*		|	|		-
*		|	|	   ---
*		|	|     -----
*	Here is the order:
* Peg A -> Peg C
* Peg A -> Peg B
* Peg C -> Peg B
* Peg A -> Peg C
* Peg B -> Peg A
* Peg B -> Peg C
* Peg A -> Peg C
* 
* 2^3 - 1 = 7, which also stands with this algorithm.
* 
* Notice that even numbers typically have us use the auxillery to hold the smallest while odd numbers have us use the destination as the auxillery, so there is definately some swapping going on there
* By this, I get the recursive call:
*	towersofHanoi(disk - 1, source, dest, aux), swapping the aux and dest pegs. Once we reach our base case, thats when we swap the top disk
* So, why do we have: another recursive call: 
*	towersofHanoi(disk - 1, aux, source, dest); ?
* Well my logic was that now that we have swapped the rods, there must be a disk that has not been swapped from a rod yet from our auxillery. Though, that logic could be flawed, and I will probably try to research it more.
* 
*   
*/
