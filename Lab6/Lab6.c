#include "Lab6.h"

void runTask1a()
{
	FILE* infile;
	infile = fopen("numbers.txt", "r");

	if (isPrime(getSum(infile)))
	{
		printf("Thats prime");
	}
	else
		printf("Not prime");

}

int readInteger(FILE* infile)
{
	int num = 0;

	fscanf(infile, " %d", &num);

	return num;
}


int isPrime(int num)
{
	for (int i = 2; i < num; i++) // Start at 0 because a prime number is divisible only by itself and 1, so if we started at 1 we would obviously get num % i == 0
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int getSum(FILE* infile)
{
	int sum = 0;

	while (!feof(infile)) // while we havent reached the bottom of the file
	{
		sum += readInteger(infile);
	}

	printf("SUM: %d", sum);
	return sum;
}

void runTaskb()
{
	FILE* infile;
	infile = fopen("numbers.txt", "r");

	int total = getTotal(getSum(infile));

	if (isPrime(total))
	{
		printf("Thats prime");
	}
	else
		printf("No");

}

int getTotal(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += num % 10; // adding the numbers in the ones place to the sum
		num /= 10; // shifting the number to the right, getting the next number in the ones place
	}

	printf("\nTotal digits: %d", sum);

	return sum;
}

void runTask2()
{
	int num = 4;
	printf("Factorial of %d = %d\n", num,  factorial(num));
}

int factorial(int num)
{
	int sum = 1;
	for (int i = 0; i < num; i++)
	{
		sum *= (num - i);
	}

	return sum;
}

void runTask3()
{
	int num = 4;
	printf("Fibb of %d = %d\n", num, fibb(num));
	printf("Fibb (with recursion!) of %d = %d\n", num, fibb_r(num));

}


int fibb(int n)
{
	int fibb1 = 0;
	int fibb2 = 1;
	int fibb3 = 0;

	// Note: We know that fibonachhi 0 is 0 and 1 is 1, so we can set those values. We get a third value to store our next fibb number
	//		This method essentially build your way up to the fibonachi we are looking for

	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;

	for (int i = 2; i <= n; i++)
	{
		fibb3 = fibb1 + fibb2;
		fibb1 = fibb2;
		fibb2 = fibb3;
	}

	return fibb3;
}

// The following function uses RECURSION to solve the fibbonachi problem
int fibb_r(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	return fibb_r(n - 1) + fibb_r(n - 2);


	// we know a fibbocnachi number is the result of the previous two fibbonachis, and we have a base case of fib(0) = 0 and fib(1) = 1.
	// By using recursion, we make our way down to the base cases, and build our way back up. This leads to cleaner code
	// Lets take the example of looking for fib(4)
	/*
	*				 fib(4)
	*		fib(3)	 		  fib(2)
	*   fib(2)  fib(1)     fib(1) fib(0)
	* fib(1) fib(0)
	*/
	// The above diagram shows the function calls that happen when we try to find fib(4)
	// we stop at fib 1 and 0 because those are our base cases. we know for certain they will return 1 or 0.
	// From there, we begin adding the result of the other function adds, which results in our final result


}

int runTask4()
{
	runGame();
}

void runGame()
{
	int input = 0, rnum = rand() % 100 + 1, guesses = 0;
	rnum -= rand() % 100 + 1; // subtracting a random number from 1-100 to allow a range from -100 to 100

	// Very helpful for PA4!
	do
	{ 
		guesses++;

		input = getInput();
		if (input < rnum)
		{
			printf("Too low!\n");
		}
		else if (input > rnum)
		{
			printf("Too high!\n");
		}
		else if (input == rnum)
		{
			printf("Correct! - Guessed in %d tries\n", guesses);
		}

	} while (input != rnum);

}

int getInput()
{
	int n;
	do
	{
		printf("Guess a number: ");
		scanf(" %d", &n);
		n > 100 ? printf("Number out of range! (-100 to 100)\n") : printf("...");
	} while (abs(n) > 100);

	return n;
}


