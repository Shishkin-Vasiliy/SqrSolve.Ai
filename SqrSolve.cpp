#include "header.h"
 
void SqrSolve (struct equation * Eq)
{	
	assert (Eq);
	
	double a = Eq -> a;
	double b = Eq -> b;
	double c = Eq -> c;

	const int INF = 1000000;
	
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


void LnrSolve(struct equation *Eq)
{	
	assert(Eq);
	
	double b = Eq -> b;
	double c = Eq -> c;

	if (Cmp(c, 0, PRECISION) == 0)
		Eq -> x1_Re = 0;
	else
		Eq -> x1_Re = -c / b;
}


void Discr(struct equation * Eq)
{
	assert(Eq);

	double a = Eq -> a;
	double b = Eq -> b;
	double c = Eq -> c;
	double D = b * b - 4 * a * c;

	Eq -> D = D;
}


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