#include "header.h"

void Discr(struct equation * Eq)
{
	assert(Eq);

	double a = Eq -> a;
	double b = Eq -> b;
	double c = Eq -> c;
	double D = b * b - 4 * a * c;

	Eq -> D = D;
}
