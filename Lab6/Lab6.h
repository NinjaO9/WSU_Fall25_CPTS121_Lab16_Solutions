#ifndef LAB6_H
#define LAB6_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void runTask1a();

int readInteger(FILE* infile);

int isPrime(int num);

int getSum(FILE* infile);

void runTaskb();

int getTotal(int num);

void runTask2();

int factorial(int num);

void runTask3();

int fibb(int n);

int fibb_r(int n);

int runTask4();

void runGame();

int getInput();

#endif