#include "Lab13.h"

int main(void)
{
	/* REVERSING A STRING RECURSIVELY */
	char str[] = "HELLO WORLD!\0";
	int len = strlen(str);
	reverseString(str);
	reverseStringTwo(str, 0, len - 1);
	printf("\n%s", str);

	/* RECURSIVE SUM OF DIGITS */
	printf("\n %d\n", sumOfDigits(198));

	/* RECURSIVE MAZE TRAVERSAL */
	char board[MAZE_SIZE][MAZE_SIZE] = {
											{WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' '},
											{WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' '},
											{WALL, ' ', WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' '},
											{WALL, ' ', WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' '},
											{WALL, ' ', WALL, ' ', WALL, WALL, WALL, WALL,WALL, ' '},
											{WALL, ' ', WALL, ' ', ' ', WALL, WALL, WALL, WALL, WALL},
											{' ', ' ', WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' '},
											{WALL, ' ', ' ', ' ', ' ', ' ', WALL, ' ', WALL, ' '},
											{WALL, ' ', WALL, ' ', WALL, ' ', WALL, WALL, WALL, ' '},
											{WALL, ' ', ' ', ' ', WALL, ' ', ' ', ' ', ' ', ' '}
	};
	traverseMaze(board, 1, 1);
	printMaze(board);

	/* TOWERS OF HANOI (lord have mercy on my soul) */
	towersofHanoi(3, 'A', 'B', 'C');
}