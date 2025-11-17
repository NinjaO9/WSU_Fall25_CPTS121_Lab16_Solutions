#ifndef LAB11_H
#define LAB11_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARTICLE_CNT 5
#define NOUN_CNT 5
#define VERB_CNT 5
#define PREPOSITION_CNT 5

void RunTask1();

void SentenceCreator(char* articles[], char* nouns[], char* verbs[], char* prepositions[]);


void RunTask2();


typedef struct coordinate
{
	int row;
	int column;
} Coordinate;

typedef struct cell
{
	int occupied; // 1 if an X or O is in this cell; 0 otherwise
	char symbol; // X for one player, O for the other player
	Coordinate location; // A struct defined above, which represents the position of the cell within the game board
} Cell;

typedef struct game_info
{
	int wins;
	int losses;
	int total_games_played;
}Game_Info;


void TicTacToe();

void InitializeBoard(Cell board[][10], int size);

void PrintBoard(Cell board[][10], int size);

void UpdateCell(char symbol, Cell* c);

int CheckDiagonal(Cell board[][10], int size);

int CheckHorizontal(Cell board[][10], int size);

int CheckVertical(Cell board[][10], int size);

int CheckForWin(Cell board[][10], int size);

void GameLoop(Cell board[][10], int size);



#endif