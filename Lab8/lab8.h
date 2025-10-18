#ifndef LAB8_H
#define LAB8
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void runTask1();

void runTask2();

int remove_whitespace(char* str, int size);

void findNextValid(char list[], int* index, int size);

void runTask3();

void runTask4();

int isNotInList(char activeGuess, char guessed[]);

void printWordProgress(char word[], char guessed[], int* correct, int size);

#endif // !LAB8_H
