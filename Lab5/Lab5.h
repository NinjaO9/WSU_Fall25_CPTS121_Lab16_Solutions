#ifndef LAB5_H
#define LAB5_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// GENERAL

double read_double(FILE* infile);

void print_double(FILE* infile, double n);


// END OF GENERAL

// TASK 1  

void runTask1();

double get_sum(FILE* infile);

void get_bracket(double sum);

// END OF TASK 1

// TASK 2

void runTask2();

double get_average(FILE* infile);

// END OF TASK 2


// TASK 3

void runTask3();

int greatest_common_divisor(int n1, int n2);

// END OF TASK 3

// TASK 4

void runTask4();

void getExtreames(FILE* infile, double* min, double* max);

// END OF TASK 4
#endif