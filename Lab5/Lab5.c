#include "Lab5.h"

void runTask1()
{
	FILE* infile = NULL;
	infile = fopen("salaries.txt", "r");

	get_bracket(get_sum(infile));
}

double read_double(FILE* infile)
{
	double num = 0.0;
	fscanf(infile, " %lf", &num);
	return num;
}

void print_double(FILE* infile, double n)
{
	fprintf(infile, " %.2lf", n);
}

double get_sum(FILE* infile)
{
	double total = 0.0;

	while (!feof(infile)) // feof - end of file (going through this loop until we reach the end of the file)
	{
		total += read_double(infile);
	}

	return total;
}

void get_bracket(double sum)
{
	if (sum >= 200000)
	{
		printf(" High income! ");
	}
	else if (sum > 15000)
	{
		printf(" Medium income! ");
	}
	else
	{
		printf(" Low income! ");
	}
}

void runTask2()
{
	FILE* infile = NULL;
	FILE* outfile = NULL;

	double average = 0.0;

	infile = fopen("data.txt", "r");
	average = get_average(infile);
	fclose(infile);


	outfile = fopen("output.txt", "w");
	print_double(outfile, average);
	fclose(outfile);

}

double get_average(FILE* infile)
{
	double sum = 0.0;
	int count = 0;
	while (!feof(infile))
	{
		sum += read_double(infile);
		count++; // count++ is shorthand for count += 1, which is also shorthand for count = count + 1
	}

	return sum / count;
}

void runTask3()
{
	printf(" %d", greatest_common_divisor(252, 735));
}

int greatest_common_divisor(int n1, int n2)
{
	int rem = n1 % n2;
	if (rem == 0)
		return n2;

	while ((n1 % n2) != 0) // remember, we want the greatest common divisor. If n1 % n2 (which is the current divisor) == 0, then n2 (also held in variable rem) is the gcd!
	{
		rem = n1 % n2;
		n1 = n2;
		n2 = rem;
	}

	return rem;
}

void runTask4()
{
	FILE* infile;
	
	double min = 0, max = 0;
	
	infile = fopen("data.txt", "r");


	getExtreames(infile, &min, &max);
	printf("Max: %.2lf   Min: %.2lf", max, min);
}

void getExtreames(FILE* infile, double* min, double* max)
{
	int count = 0;
	double n = 0;
	*min = read_double(infile); // the * operator here is dereferencing the variable min and max to access their literal values
	*max = *min;

	for (; !feof(infile); count++) // Using the for-loop like a while-loop
	{
		n = read_double(infile);
		if (n > *max)
		{
			*max = n;
		}
		if (n < *min)
		{
			*min = n;
		}
	}

	printf("Max: %p   Min: %p\n", max, min); 
	// %p orints out the memory address of the max and min. Notice that we only pass in max and min without any modifiers. 
	// Thats because max and min are already pointers to the original values of max and min! 

}

/*
* 
* For task 4 I used pointers to 'return' two variables as an output!
*	Pointers are very useful for manipulating the original copy of an object, (which you guys will learn more about in the next lab)
*	
* 
*/

