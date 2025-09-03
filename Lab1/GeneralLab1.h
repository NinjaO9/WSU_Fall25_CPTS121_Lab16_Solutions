#ifndef GEN_H
#define GEN_H

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14 // <- Used for Task2e    This is a constant variable, it cannot be changed (thus the name)
#include <stdio.h>

int RunTask1(void); // <- This is a function declaration! We are declaring that there is a function that follows these parameters. (returns an integer and takes no parameters)

int RunTask2a(void);

int RunTask2b(void);

int RunTask2c(void);

int RunTask2d(void);

int RunTask2e(void);

#endif

/*
* This is a header file. Andy will likely talk more about it soon, but you can think of it like a hub for anything that might be commonly used between multiple files
* The compliment of this file (GeneralLab1.c), contains all the function DEFINITIONS for all the function DECLARATIONS in this file.
* 
* Its ok if it doesn't make sense yet, I'm sure Andy will go over header files soon. If you do want to learn more though, feel free to send any questions my way!
*/