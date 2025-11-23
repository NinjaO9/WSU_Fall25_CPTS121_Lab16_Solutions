#pragma once
#ifndef LAB13_H
#define LAB13_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAZE_SIZE 10
#define GOAL_COORD 7
#define WALL '#'
#define TRAVEL_MARKER 'O'

void reverseString(char* c);

void reverseStringTwo(char string[], int start, int end);

int sumOfDigits(int num);


void printMaze(char board[][MAZE_SIZE]);

int traverseMaze(char board[][MAZE_SIZE], int x, int y);

void towersofHanoi(int disk, char source, char aux, char dest);

#endif