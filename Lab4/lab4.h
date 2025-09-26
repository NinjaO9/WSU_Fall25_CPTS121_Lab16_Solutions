#ifndef LAB4_H
#define LAB4_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef enum gender
{
	MAN,
	WOMAN
}Gender;

typedef enum activity
{
	SEDINTARY = 1,
	LOW,
	MODERATE,
	HIGH,
	EXTREAME
}Activity;

/*
* 
* Note about above:
*		These are enums! (enumerators)
*		They allow me to represent a keyphrase as a number, which can make
*			my code easier to read. Enums start at 0 (unless specified otherwise, like in activity) and increment by 1 for each entry!
* 
*/

// GENERAL
double read_double(FILE* infile);

int read_int(FILE* infile);

char lower(char c); // Ever use python? We are essentially implementing the .lower() function for strings/characters!

// END OF GENERAL


// TASK 1 & 2

void runTask2();

double getBMR(Gender gender, double weight, double height, double age);

double getCaloricNeeds(Activity activity, double BMR);

// END OF TASK 1 & 2

// TASK 3

void runTask3();

int getResponse();


// END OF TASK 3

// TASK 4

void runTask4();

void findMin(FILE* infile);

void findMax(FILE* infile);

void findAverage(FILE* infile);

int getMode();

// END OF TASK 4

#endif