#include "lab12.h"

int ReadEmployees(Employee payroll[])
{
	FILE* infile = fopen("payroll.txt", "r");
	char extra = '\0';
	int count = 0;
	for (; !feof(infile) && count < 200; count++)
	{
		fgets(payroll[count].name, 100, infile);
		fscanf(infile, " %c", &payroll[count].title);
		fscanf(infile, " %lf", &payroll[count].hours_worked);
		fscanf(infile, " %lf", &payroll[count].payrate);
		fscanf(infile, "%c", &extra);
	}
	fclose(infile);
	return count;
}

void GetPaymentStats(Employee payroll[], int count)
{
	FILE* outfile = fopen("paid.txt", "w");
	double maxPay = INT_MIN, minPay = INT_MAX, avgPay = 0, totPay = 0, newPay = 0;
	for (int i = 0; i < count; i++)
	{
		newPay = CalculatePayment(&payroll[i]);
		if (newPay > maxPay)
			maxPay = newPay;
		if (newPay < minPay)
			minPay = newPay;
		totPay += newPay;
	}
	avgPay = totPay / count;

	fprintf(outfile, "Total Pay:  %.2lf\n", totPay);
	fprintf(outfile, "Average Pay: %.2lf\n", avgPay);
	fprintf(outfile, "Max Pay: %.2lf\n", maxPay);
	fprintf(outfile, "Min Pay: %.2lf\n", minPay);
	fclose(outfile);
}

double CalculatePayment(Employee* emp)
{
	double overtime = 0;
	if (emp->hours_worked <= 80)
	{
		emp->payment = emp->payrate * emp->hours_worked;
	}
	else if (emp->title == 'B')
	{
		overtime = emp->hours_worked - 80;
		emp->payment = (emp->payrate * 80) + overtime * (emp->payrate * 1.5);
	}
	else if (emp->title == 'M')
	{
		overtime = emp->hours_worked - 80;
		emp->payment = (emp->payrate * 80) + overtime * (emp->payrate * 1.8);
	}
	return emp->payment;
}
