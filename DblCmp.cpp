#include "header.h"

int Cmp(double a, double b, int Accuracy)
{
	double epsilon = pow(10, -Accuracy); // todo

	if (fabs(a - b) < epsilon)
		return 0;
	else if ((a - b) > epsilon)
		return 1;
	else 
		return -1;
}
