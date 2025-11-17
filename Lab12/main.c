#include "lab12.h"

int main(void)
{
	Employee payroll[200] = { NULL };

	int count = ReadEmployees(payroll);
	GetPaymentStats(payroll, count);
}