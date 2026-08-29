#include "header.h"

void ClearBuf(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n')
		;
}
 
void FileClearBuf(FILE *file)
{
    assert(file);
    
    int ch = 0;
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
        ;
}