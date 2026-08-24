#include "header.h"

int GetKoeff(struct equation *Eq)
{
	assert(Eq);

	const int NUM_KOEFFS = 3;
	int ch = 0;
	int state = 0;

	while ((state = scanf("%lg%lg%lg", &(Eq -> a), &(Eq -> b), &(Eq -> c))) != NUM_KOEFFS)
	{
	       if ((ch = getchar()) == 'q')
		       return 0;
			   
			ClearBuf();	
	}
	return state;
}