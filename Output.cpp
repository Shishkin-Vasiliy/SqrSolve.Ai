#include "header.h"

void Output(struct equation *Eq)
{	
	assert(Eq);

	int nRoots = Eq -> nRoots;

	printf("\n");
	
    switch(nRoots)
		{
			case ONE_ROOT:
			{
				PrintOneRoot(Eq);
			}
				break;

			case TWO_ROOTS:
			{
				PrintTwoRoots(Eq);
			}
				break;

			case COMPLEX_ROOTS:
			{
				PrintComplexRoots(Eq);
			}
				break;

			case INF_ROOTS:
				PrintInfRoots();
				break;

			default:
				PrintDefaultRoots();
				break;
		}	
}
