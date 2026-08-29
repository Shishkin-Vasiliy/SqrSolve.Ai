#include "header.h"

/** 
	\brief Функция, считывающая коэффициенты из терминала в структуру уравнения.
*/

int GetCoeff(struct equation *Eq)
{
	assert(Eq);

	const int NUM_COEFFS = 3;
	int ch = 0;
	int state = 0;

	while ((state = scanf("%lg %lg %lg", &(Eq -> a), &(Eq -> b), &(Eq -> c))) != NUM_COEFFS)
	{
	    if ((ch = getchar()) == 'q')
		    return 0;

		ClearBuf();	  	
	}
	ClearBuf();
	
	return state;
}

