#include "header.h"

void SetFlag (int *nEquations, int *flag)
{
	assert(nEquations);
	assert(flag);
	
    if (*nEquations == BUF_SIZE)
		{
			*nEquations = 0;
			*flag = 1;
		}
	else if (*nEquations == BUF_SIZE - 1)
		{
			*flag = 0;
		}
}