#include "lab11.h"

void RunTask1()
{
	char* articles[] = {"the", "a", "one", "some", "any"};
	char* noun[] = {"boy", "girl", "dog", "town", "car"};
	char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
	char* preposition[] = {"to", "from", "over", "under", "on"};

	for (int i = 0; i < 10; i++)
	{
		SentenceCreator(articles, noun, verb, preposition);
	}
}

void SentenceCreator(char* articles[], char* nouns[], char* verbs[], char* prepositions[])
{
	//: article, noun, verb, preposition, article, and noun

	int r = 0;
	r = rand() % 5;
	char str[100] = { '\0' };
	strcpy(str, articles[r]);
	str[0] -= 32; // Uppercase first letter

	printf("%s", str);

	// Loop to print other words
	for (int i = 0; i < 5; i++)
	{
		r = rand() % 5;
		switch (i)
		{
		case 0:
			printf(" %s", nouns[r]);
			break;
		case 1:
			printf(" %s", verbs[r]);
			break;
		case 2:
			printf(" %s", prepositions[r]);
			break;
		case 3:
			printf(" %s", articles[r]);
			break;
		case 4:
			printf(" %s", nouns[r]);
			break;
		}
	}
	printf("!\n");
}














void RunTask2()
{
	TicTacToe();
}

void TicTacToe()
{
	int size = 0;
	char input[2] = { '\0' };
	printf("Provide a board size: ");
	fgets(input, 2, stdin);
	size = atoi(input);
	Cell board[10][10] = { {{.location = {.column = 0, .row = 0}}} };
	InitializeBoard(board, size);
	GameLoop(board, size);

}

void GameLoop(Cell board[][10], int size)
{
	int c1 =0, c2 = 0;
	int winner = 0;
	int rounds = 0;
	do
	{
		printf("Player X turn! Enter coordinates to place symbols!\n");
		scanf("%d %d", &c1, &c2);
		UpdateCell('X', &(board[c1][c2]));
		PrintBoard(board, size);
		winner = CheckForWin(board, size);
		if (winner)
			break;
		printf("Player O turn! Enter coordinates to place symbols!\n");
		scanf("%d %d", &c1, &c2);
		UpdateCell('O', &(board[c1][c2]));
		PrintBoard(board, size);
		winner = CheckForWin(board, size);
		rounds += 2;

	} while (!CheckForWin(board, size) && rounds != size * size);

	if (winner == 1)
	{
		printf("Winner X");
	}
	else if (winner == 2)
	{
		printf("WInner O");
	}
	else
	{
		printf("tie");
	}
}


void InitializeBoard(Cell board[][10], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j].location.column = j;
			board[i][j].location.row = i;
			board[i][j].symbol = ' ';
			board[i][j].occupied = 0;
		}
	}
}

void PrintBoard(Cell board[][10], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			//printf(" %c ", ((board + i) + j)->symbol); <- Alternatively
			printf(" %c ", board[i][j].symbol);
			printf("|");
		}
		printf(" %c\n", board[i][size-1].symbol);
		for (int j = 0; j < size && i + 1 < size; j++)
		{
			if (j + 1 == size)
			{
				printf("---\n");
			}
			else
			{
				printf("---|");
			}
		}

	}
	printf("\n");
}

void UpdateCell(char symbol, Cell* c)
{
	if ((c)->occupied) return;
	(c)->symbol = symbol;
	(c)->occupied = 1;
}

int CheckDiagonal(Cell board[][10], int size)
{
	char tracking = '\0';
	tracking = board[0][0].symbol;
	for (int row = 0, col = 0; row < size; row++, col++)
	{
		if (tracking == ' ')
			break;
		if (board[row][col].symbol != tracking)
		{
			break;
		}
		if (col + 1 == size)
		{
			if (tracking == 'O')
			{
				return 2;
			}
			return 1;
		}
	}
	tracking = board[size - 1][0].symbol;
	for (int row = size - 1, col = 0; row > 0; row--, col++)
	{
		if (tracking == ' ')
			break;
		if (board[row][col].symbol != tracking)
		{
			break;
		}
		if (col + 1 == size)
		{
			if (tracking == 'O')
			{
				return 2;
			}
			return 1;
		}
	}

	return 0;
}

int CheckHorizontal(Cell board[][10], int size)
{
	char tracking = '\0';
	for (int row = 0; row < size; row++)
	{
		tracking = board[row][0].symbol;
		if (tracking == ' ')
			continue;
		for (int col = 0; col < size; col++)
		{
			if (board[row][col].symbol != tracking)
			{
				break;
			}
			if (col + 1 == size)
			{
				if (tracking == 'O')
				{
					return 2;
				}
				else if (tracking == 'X')
					return 1;
			}
		}
	}
	return 0;
}

int CheckVertical(Cell board[][10], int size)
{
	char tracking = '\0';
	for (int col = 0; col < size; col++)
	{
		tracking = board[0][col].symbol;
		if (tracking == ' ')
			continue;
		for (int row = 0; row < size; row++)
		{
			if (board[row][col].symbol != tracking)
			{
				break;
			}
			if (row + 1 == size)
			{
				if (tracking == 'O')
				{
					return 2;
				}
				return 1;
			}
		}
	}
	return 0;
}

int CheckForWin(Cell board[][10], int size)
{
	int winFound = 0;

	winFound = CheckHorizontal(board, size);
	if (!winFound)
		winFound = CheckDiagonal(board, size);
	if (!winFound)
		winFound = CheckVertical(board, size);

	return winFound;
}
