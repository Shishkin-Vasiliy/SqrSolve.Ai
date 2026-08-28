#include "header.h"

#define INF 1000000
 
void SqrSolve (struct equation * Eq)
{	
	assert (Eq);
	
	double a = Eq -> a;
	double b = Eq -> b;
	double c = Eq -> c;

	assert (a < INF);
	assert (b < INF);
	assert (c < INF);
	
	if (Cmp(a, 0.0, PRECISION) == 0)
	{
		if (Cmp(b, 0.0, PRECISION) == 0)
		{
			Eq -> nRoots = (Cmp(c, 0.0, PRECISION) == 0) ? c : INF_ROOTS;
		}
		else  
		{
			LnrSolve(Eq);
			Eq -> nRoots = ONE_ROOT;
		}
	}
	else          
	{
		Discr(Eq);
		double D = Eq -> D;

		if (Cmp(D, 0.0, PRECISION) == 0)     
		{
			Eq -> x1_Re = (-b + sqrt(D)) / (2 * a);
			Eq -> nRoots = ONE_ROOT;
		}
		else if (Cmp(D, 0.0, PRECISION) == 1)  
		{
			Eq -> x1_Re = (-b + sqrt(D)) / (2 * a);
			Eq -> x2_Re = (-b - sqrt(D)) / (2 * a);
			Eq -> nRoots = TWO_ROOTS;
		}
		else            
		{
			Eq -> x1_Re = -b / (2 * a);
			Eq -> x1_Im = sqrt(-D) / (2 * a);

			Eq -> x2_Re = -b / (2 * a);
			Eq -> x2_Im = -sqrt(-D) / (2 * a);

			Eq -> nRoots = COMPLEX_ROOTS;
		}	
	}
}	
