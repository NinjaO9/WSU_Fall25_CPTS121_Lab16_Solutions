#ifndef LAB7_H
#define LAB7_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// TASK 1
#define INITIAL_COUNT 3
#define ARR_SIZE (INITIAL_COUNT + 1)

void run_task1();

void get_initial(char* first, char* middle, char* last);

void get_arr_initial(char initials[]);

//END OF TASK 1 CODE

// TASK 2

void run_task2();

void charges(int hours, double* charge, double* rate);

double round_money(double number);

void print_details(int hours, double charge, double rate);

// END OF TASK 2

// TASK 3

void run_task3();

void revenue(int t, double* R);

void predict(double millions, int* years);

// END OF TASK 3


#endif