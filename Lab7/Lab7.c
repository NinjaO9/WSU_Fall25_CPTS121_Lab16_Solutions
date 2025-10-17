#include "Lab7.h"

void run_task1()
{
	char first = '\0', middle = '\0', last = '\0';
	printf("Enter initials: \n");
	get_initial(&first, &middle, &last);
	printf("Initials: %c, %c, %c\n", first, middle, last);


	// Extra Array function
	char initials[ARR_SIZE] = { '\0' };
	printf("Enter initials (limit: %d)\n", INITIAL_COUNT);
	get_arr_initial(initials);
	printf("Initials: %s\n\n", initials);
}

void get_initial(char* first, char* middle, char* last)
{
	scanf(" %c", first);
	scanf(" %c", middle);
	scanf(" %c", last);
}

void get_arr_initial(char initials[])
{
	for (int i = 0; i < INITIAL_COUNT; i++)
	{
		scanf(" %c", &initials[i]);
	}
}

void run_task2()
{
	FILE* infile = fopen("input.txt", "r");
	double hours = 0, charge = 0, rate = 0;
	while (!feof(infile))
	{
		fscanf(infile, " %lf", &hours);
	}

	charges(hours, &charge, &rate);
	print_details(hours, charge, rate);
}

void charges(int hours, double* charge, double* rate)
{
	if (hours <= 10)
	{
		*charge = 7.99;
		*rate = (*charge)/hours;
	}
	else
	{
		hours -= 10;
		*charge = (hours * 1.99) + 7.99;
		*rate = (*charge)/hours;
	}
}

double round_money(double number)
{
	int inum = number;
	double decimals = number - inum;

	decimals *= 1000;
	if (((int)decimals % 10) > 4)
	{
		decimals = decimals - ((int)decimals % 10);
		return (double)inum + (int)decimals / 1000.0 + 0.01;
	}
	return inum + (decimals - (int)decimals % 10)/1000;
}

void print_details(int hours, double charge, double rate)
{
	FILE* outputFile = fopen("output.txt", "w");
	fprintf(outputFile, "==== Output Stats ====\n");
	fprintf(outputFile, "Hours: %d\n", hours);
	fprintf(outputFile, "Total Charge: $%.2lf\n", charge);
	fprintf(outputFile, "Rate: $%.2lf an hour", rate);
}

void run_task3()
{
	int years = 0;
	predict(1000, &years);
	printf("Year prediction: %d", years);
}

void revenue(int t, double* R)
{
	*R = 203.265 * pow(1.071, t);
}

void predict(double millions, int* years)
{
	double R = 0;
	FILE* output = fopen("predict.txt", "w");
	revenue(*years, &R);
	fprintf(output, "REVENUE | YEAR\n");
	fprintf(output, "%.2lf | %d\n", R, *years + 1984);

	while (R < millions)
	{
		(*years)++;
		revenue(*years, &R);
		fprintf(output, "%.2lf | %d\n", R, *years + 1984);
	}
	*years += 1984;
}
