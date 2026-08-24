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
				PrintOne(Eq);
			}
				break;

			case TWO_ROOTS:
			{
				PrintTwo(Eq);
			}
				break;

			case COMPLEX_ROOTS:
			{
				PrintComplex(Eq);
			}
				break;

			case INF_ROOTS:
				PrintInf();
				break;

			default:
				PrintDefault();
				break;
		}	
}
