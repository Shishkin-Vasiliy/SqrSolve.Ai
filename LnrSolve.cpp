#include "header.h"

void LnrSolve(struct equation *Eq)
{	
	assert(Eq);
	
	double b = Eq -> b;
	double c = Eq -> c;

	if (Cmp(c, 0, FOUR_DIGITS) == 0)
		Eq -> x1_Re = 0;
	else
		Eq -> x1_Re = -c / b;
}
