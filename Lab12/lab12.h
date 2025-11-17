#ifndef LAB12_H
#define LAB12_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct employee
{
	char name[100];
	char title;
	double hours_worked;
	double payrate;
	double payment;
}Employee;

int ReadEmployees(Employee payroll[]);

double CalculatePayment(Employee* emp);

void GetPaymentStats(Employee payroll[], int count);


#endif