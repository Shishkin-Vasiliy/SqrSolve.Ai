#include "header.h"

#define INF 1000000
 
void SqrSolve (struct equation * Eq)
{	
	assert (Eq);
	
	// проверяем входные данные
	
	double a = Eq -> a;
	double b = Eq -> b;
	double c = Eq -> c;

	assert (a < INF);
	assert (b < INF);
	assert (c < INF);

	// анализируем введенные коэффициенты
	
	if (Cmp(a, 0.0, FOUR_DIGITS) == 0)
	{
		if (Cmp(b, 0.0, FOUR_DIGITS) == 0)
		{
			Eq -> nRoots = (Cmp(c, 0.0, FOUR_DIGITS) == 0) ? c : INF_ROOTS;
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

		if (Cmp(D, 0.0, FOUR_DIGITS) == 0)      // случай с одним корнем
		{
			Eq -> x1_Re = (-b + sqrt(D)) / (2 * a);
			Eq -> nRoots = ONE_ROOT;
		}
		else if (Cmp(D, 0.0, FOUR_DIGITS) == 1)  // случай с 2 корнями
		{
			Eq -> x1_Re = (-b + sqrt(D)) / (2 * a);
			Eq -> x2_Re = (-b - sqrt(D)) / (2 * a);
			//printf("x2_Re = %lg\n", Eq -> x2 -> Re);
			Eq -> nRoots = TWO_ROOTS;
		}
		else             // случай с комлексными корнями
		{
			Eq -> x1_Re = -b / (2 * a);
			Eq -> x1_Im = sqrt(-D) / (2 * a);

			Eq -> x2_Re = -b / (2 * a);
			Eq -> x2_Im = -sqrt(-D) / (2 * a);

			Eq -> nRoots = COMPLEX_ROOTS;
		}
		
	}
}	
