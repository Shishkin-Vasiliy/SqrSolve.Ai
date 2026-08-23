#include "header.h"

void LnrSolve(struct equation *Eq)
{	
	double b = Eq -> b;
	double c = Eq -> c;

	Eq -> x1 -> Re = -c / b;
}
