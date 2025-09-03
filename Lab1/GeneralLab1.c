/*****************************************************************
* Programmer: David Montes
* Class: CptS 121, Fall 2025; Lab Section 16
* Programming Assignment: Lab1 - SOLUTION
* Date: August 28, 2025
* Description: Code behind all task solutions
*****************************************************************/


#include "GeneralLab1.h"

/* Print general "Hello World" message to terminal */
int RunTask1(void)
{
	printf("Hello World, I am in Cpts 121!\n");

	return 0;
}

/* Perform operations between integers and floating point numbers and experiment with casting and modulus operator. */
int RunTask2a(void)
{

	int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
	double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for numbers with high precision (floating-point)
	printf("Enter two integer values: "); // prompt/ask the user
	scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the keyboard - %d is for "decimal", i.e. integers
	printf("Enter two floating-point values: "); // prompt/ask the user
	scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through the keyboard - %lf is for "long float", i.e. double precision numbers

	if (number2_float == 0 || number2_int == 0) { printf("Invalid entry found! (Preventing divide by 0 error)\n"); return -1; } // Don't worry about this, this is just protection form the program crashing due to trying to divide by 0!

	// add operation:
	printf("%d + %d = %d\n", number1_int, number2_int, number1_int + number2_int);

	// subtract operation:
	printf("%lf - %lf = %lf\n", number1_float, number2_float, number1_float - number2_float);

	// multiply operation:
	printf("%d * %lf = %d\n", number1_int, number1_float, (int)(number1_int*number1_float));

	// divide operation (int on int):
	printf("%d / %d = {integer: %d, float: %lf}\n", number1_int, number2_int, (int)(number1_int / number2_int), /* Note: This is EXPLICIT casting -> */(double)(number1_int / number2_int)); // note that we didnt cast the integers as floats, so the result will be the same as the integer division!

	// divide operation (int on float):
	printf("%d / %lf = {integer: %d, float: %lf}\n", number1_int, number2_float, (int)(number1_int / number2_float), (double)(number1_int / number2_float));

	// divide operation (float(int) on int):
	printf("(int cast as float) %lf / %d = %lf\n", (double)number1_int, number2_int, (double)number1_int / number2_int);

	// mod attempt:
	printf("%lf mod %lf = %lf\n", number1_float, number2_float, (float)((int)number1_float%(int)number2_float)); // NOTE: The modulo operator does not work on floating decimal numbers.(Though some libraries and other languages have support for float mod float)


	/*
	* For the modulo, we will write 0 if the number is even and 1 if the number is odd.
	* 
	* This follows the definition of an even number: n = 2k  (where k is any integer)
	* By definition, any even number should be divisible by 2 without remainder. Thus, if there is a remainder, it is an odd number.
	* 
	*/

	// is nunm1 even or odd?
	printf("Is %d odd: %d\n", number1_int, number1_int % 2); // The modulo operator returns the REMAINDER of a division problem. For example: 3 % 2 = 1. Reversely, 2 * 1 = 2; 2 + 1 = 3

	// is num2 even or odd?
	printf("Is %d odd: %d\n", number2_int, number2_int % 2);


	return 0;
}

/* Calculate Voltage via Ohlm's Law */
int RunTask2b(void)
{
	int current = 0, resistance = 0;
	printf("Enter the current: ");
	scanf("%d", &current);
	printf("Enter the resistence: ");
	scanf("%d", &resistance);
	// You do not have to seperate them (inputs of ints), I just did as a stylistic choice

	printf("Through Ohlm's Law, the voltage is: %d\n", current * resistance);

	return 0;
}

/* Calculate power through Joule's Law */
int RunTask2c(void)
{
	int voltage = 0, resistance = 0;
	printf("Enter the voltage: ");
	scanf("%d", &voltage);
	printf("Enter the resistence: ");
	scanf("%d", &resistance);

	printf("Through Ohlm's Law, the voltage is: %.3lf\n", (double)(voltage * voltage)/(double)resistance); 
											// Something interesting: I write "%.3lf", the '.3' indicates that I only want at most 3 number AFTER the decimal
													// To explain the equation a little more: I cast voltage*voltage (effectively voltage^2) to a double, along with the resistance. This allows me to have a double as a result of dividing
	return 0;
}

int RunTask2d(void)
{
	// y = 3 * ax3 + (1/4) * bx2 + 10 * cx + (-5) *d      (x, y, a, b, c, and d are integer numbers)
	int a = 0, b = 0, c = 0, d = 0, x = 0;
	printf("Enter values for a, b, c, d, and x: ");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &x); // Im not doing seperate this time cause im lazy xd

	printf("The result of the equation is: %d\n", (int)(3 * a * x * 3 + 1.0/4.0 * b * x * 2 + 10 * c * x + (-5) * d)); // I explicitly cast the entire equation into an integer because 1.0/4.0 makes the entire equation evaluate as a flaoting point number
						// There are like three ways to go about this off the top of my head:
							// Either replace 1/4 with 0.25, 
							// cast 1 and 4 into floats individually, 
							// or implicitly cast them by writing 1.0/4.0
	return 0;
}

int RunTask2e(void)
{
	double radius = 0.0;
	printf("Enter the radius of the circle: ");
	scanf("%lf", &radius);

	printf("The circumfrence of the circle is: %.3lf", 2 * PI * radius);

	return 0;
}

/*
	If you are wondering "Where is PI defined?", look inside the GeneralLab1.h file
*/
