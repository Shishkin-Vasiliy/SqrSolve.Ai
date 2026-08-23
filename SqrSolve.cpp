#include "header.h"

#define INF 1000000
 
void SqrSolve (struct equation *Eq)
{	
	// проверяем входные данные
	
	double a = Eq -> a;
	double b = Eq -> b;
	double c = Eq -> c;

	assert (a < INF);
	assert (b < INF);
	assert (c < INF);

	assert (Eq);

	// анализируем введенные коэффициенты
	
	if (Cmp(a, 0.0) == 0)
	{
		if (Cmp(b, 0.0) == 0)
		{
			Eq -> nRoots = (Cmp(c, 0.0) == 0) ? c : INF_ROOTS;
		}
		else  // случай линейного уравнения
		{
			LnrSolve(Eq);
			Eq -> nRoots = ONE_ROOT;
		}
	}
	else          // случай квадратного уравнения
	{
		Discr(Eq);
		double D = Eq -> D;

		if (Cmp(D, 0.0) == 0)      // случай с одним корнем
		{
			Eq -> x1 -> Re = (-b + sqrt(D)) / (2 * a);
			Eq -> nRoots = ONE_ROOT;
		}
		else if (Cmp(D, 0.0) == 1)  // случай с 2 корнями
		{
			Eq -> x1 -> Re = (-b + sqrt(D)) / (2 * a);
			Eq -> x2 -> Re = (-b - sqrt(D)) / (2 * a);
			Eq -> nRoots = TWO_ROOTS;
		}
		else             // случай с комлексными корнями
		{
			Eq -> x1 -> Re = -b / (2 * a);
			Eq -> x1 -> Im = sqrt(-D) / (2 * a);

			Eq -> x2 -> Re = -b / (2 * a);
			Eq -> x2 -> Im = -sqrt(-D) / (2 * a);

			Eq -> nRoots = COMPLEX_ROOTS;
		}
	}
}	
