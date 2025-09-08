#include "LabTasks.h"

/*
* Prompts user for two points on a graph, and then calculates the slope, y-intercept of perpendicular bisector, and equation of the perpendicular bisector
*/
void RunTask1()
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0, slope = 0, yintercept = 0;
	printf("Enter two coordinate points in the form 'x,y'(example: 3,2)\n");
	scanf("%lf,%lf", &x1, &y1);
	scanf("%lf,%lf", &x2, &y2);
	slope = (y2 - y1) / (x2 - x1);
	yintercept = y1 - (-1 * slope) * x1;
	printf("The slope between the points is: %.3lf\n", slope);
	printf("The midpoint is: (%.3lf, %.3lf)\n", (x2 + x1) / 2, (y1 + y2) / 2);
	printf("The y-intercept of the perpindicular bisector is: %.3lf\n", yintercept); // math: slope intercept form: y = mx + b | b is the y-intercept. To solve for b: y - mx = b. We multiply the slope by -1 because the perpindicular bisector will have the opposite slope to be perpindicular
	printf("The equation of the perpindicular bisector is: y = %.3lf * %.3lf + %.3lf\n", slope, x1, yintercept);

}

/*
* Prompts user for their weight in pounds and their height in feet. Then, calculates BMI based on given information (converting height into inches)
*/
void RunTask2()
{
	double weight = 0, height = 0, BMI = 0;
	printf("Please enter your weight (in pounds): ");
	scanf("%lf", &weight);
	printf("Please enter your height (in feet): ");
	scanf("%lf", &height);
	height *= 12; // Note: *= is a shorthand for height = height * 12;  There are other version of this such as: += -= /= *= ++ --
	BMI = (weight / (height * height)) * 703;
	if (BMI < 18)
		printf("Your BMI scale of %.0lf indicates you are underweight!\n", BMI);
	else if (BMI >= 18 && BMI < 25)
		printf("Your BMI scale of %.0lf indicates you are healthy weight!\n", BMI);
	else
		printf("Your BMI scale of %.0lf indicates you are overweight!\n", BMI);

	/*
	* Notice:
	*		I dont have any curly braces for my if statements! 
	*			Usually you should have curly braces for your if statements, but if the if statement only executes one line, then you do not need to have the curly braces for execution!
	*		
	*/

}

/*
* Same task as RunTask2, but rather than using IF STATEMENTS, we use the TURNARY OPERATOR
* NOTE: The Lab does NOT ask that we do this, but I think it would be an interesting topic to cover
*		If you would like to see that both functions act the same, you can uncomment the function in Main.c
*/
void RunTask2Modified()
{
	double weight = 0, height = 0, BMI = 0;
	printf("Please enter your weight (in pounds): ");
	scanf("%lf", &weight);
	printf("Please enter your height (in feet): ");
	scanf("%lf", &height);
	height *= 12; 
	BMI = (weight / (height * height)) * 703;

	BMI > 25 ? printf("Your BMI scale of %.0lf indicates you are overweight!\n", BMI) : BMI < 25 && BMI >= 18 ? printf("Your BMI scale of %.0lf indicates you are healthy weight!\n", BMI) : printf("Your BMI scale of %.0lf indicates you are underweight!\n", BMI);
	/*
	* 
	* Above we are using what is known as the [ Turnary Operator ].
	* The format of the operator goes like this:   (expression) ? (action if true) : (action if false)
	* In the above code, we are leveraging that to CHAIN the turnary operator to have multiple conditions, and it acts the exact same as the if statement block in the normal task function!
	*
	*/

}