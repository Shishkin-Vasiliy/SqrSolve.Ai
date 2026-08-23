#include "header.h"

void ClearBuf(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n')
		;
}
 