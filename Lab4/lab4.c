#include "lab4.h"

double read_double(FILE* infile)
{
	double num = 0.0;
	fscanf(infile, " %lf", &num);
	return num;
}

int read_int(FILE* infile)
{
	int num = 0;
	fscanf(infile, " %d", &num);
	return num;
}

char lower(char c)
{
	if (c <= 90)
		return (c += 32); // Remember, Upper -> lower case letters are 32 characters difference
	return c;
}


void runTask2()
{
	FILE* infile = NULL;
	infile = fopen("Task2.txt", "r");
	int gender = 0, activity_lvl = 0;
	double weight = 0.0, height = 0.0, age = 0.0, caloricNeed = 0.0;

	// Getting our numbers from the file
	gender = read_int(infile);
	age = read_double(infile);
	weight = read_double(infile);
	height = read_double(infile);
	activity_lvl = read_int(infile);

	// Getting caloric needs, with the return value of the getBMR function as a direct argument because we do not need BMR otherwise
	caloricNeed = getCaloricNeeds(activity_lvl, getBMR(gender, weight, height, age));
	printf("Calories Needed: %.2lf\n", caloricNeed);
}

double getBMR(Gender gender, double weight, double height, double age)
{
	double BMR = 0.0;
	switch (gender)
	{
	case MAN:
		BMR = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
		break;
	case WOMAN:
		BMR = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
		break;
	}
	return BMR;
}

double getCaloricNeeds(Activity activity, double BMR)
{
	double calories = 0.0;
	switch (activity)
	{
	case SEDINTARY:
		calories = BMR * 1.2;
		break;
	case LOW:
		calories = BMR * 1.375;
		break;
	case MODERATE:
		calories = BMR * 1.55;
		break;
	case HIGH:
		calories = BMR * 1.725;
		break;
	case EXTREAME:
		calories = BMR * 1.9;
		break;
	}
}

void runTask3()
{
	int bonus = 0;
	printf("Were you an All-Star Game appearance? (y/n) ");
	if (getResponse())
		bonus += 25000;

	printf("Were you a Regular season MVP? (y/n) ");
	if (getResponse())
		bonus += 75000;

	printf("Were you World Series MVP? (y/n) ");
	if (getResponse())
		bonus += 100000;

	printf("Were you a Gold Glove award winner? (y/n) ");
	if (getResponse())
		bonus += 50000;

	printf("Were you a Silver Slugger award winner? (y/n) ");
	if (getResponse())
		bonus += 35000;

	printf("Were you a Home run champ? (y/n) ");
	if (getResponse())
		bonus += 25000;

	printf("Were you a Batting average champ? (y/n) ");
	if (getResponse())
		bonus += 25000;

	printf("\n Your total bonus is: %d", bonus);
}

int getResponse()
{
	char response = '\0';
	scanf(" %c", &response);
	if (lower(response) == 'y')
	{
		return 1; // 1 = true in an if statement
	}
	else if (lower(response) == 'n')
	{
		return 0; // 0 = false in an if statement
	}
	return getResponse(); // We can call functions inside of each other! This is called Recursion, which is a very important concept that will be covered later in the semester!
					// Here, we are forcing the user to either input a 'y' or 'n' (or uppercase, our lower() function forces the input to be the lowercase equivalent if it is not already)
}

void runTask4()
{
	FILE* infile = NULL;
	infile = fopen("Task4.txt", "r");
	printf("Would you like to:\n");
	printf("1) Find the min\n");
	printf("2) Find the max\n");
	printf("3) Find the average\n");
	switch (getMode())
	{
	case 1:
		findMin(infile);
		break;
	case 2:
		findMax(infile);
		break;
	case 3:
		findAverage(infile);
		break;
	}

	
}

void findMin(FILE* infile)
{
	double min = read_double(infile);
	double new_n = 0;

	while (!feof(infile)) // Using loops!
	{
		new_n = read_double(infile);
		if (min > new_n)
		{
			min = new_n;
		}
	}
	
	printf("The min is: %.2lf", min);
}

void findMax(FILE* infile) // Basically the same logic as min, just slightly changed
{
	double max = read_double(infile);
	double new_n = 0;

	while (!feof(infile)) // Using loops!
	{
		new_n = read_double(infile);
		if (max < new_n)
		{
			max = new_n;
		}
	}

	printf("The max is: %.2lf", max);
}

void findAverage(FILE* infile)
{
	double sum = read_double(infile);
	int count = 1;
	while (!feof(infile)) // Using loops!
	{
		count++; // increments count by 1
		sum += read_double(infile);
	}

	printf("The average is: %.2lf", sum / count);
}

int getMode()
{
	char count = 0;
	scanf(" %c", &count);
	if (count < 49 || count > 51) // Only valid numbers are 1 - 3, ASCII codes for comparison
		return getMode();
	return count - 48; // 1 = 49, 2 = 50, 3 = 51 in ASCII | 49 - 48 = 1, 50 - 49 = 2, 51 - 49 = 3. See why we do this? 
}
