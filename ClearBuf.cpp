#include "header.h"
/**
	\brief Очищает буфер ввода.
*/
int ClearBuf(void)
{
	int garbage = 0;
	int ch = 0;
	while ((ch = getchar()) != '\n')
		if (!isspace(ch))
			garbage = 1;
	return garbage;	
}
 
/**
	\brief Очищает буфер ввода из файла.
*/
void FileClearBuf(FILE *file)
{
    assert(file);
    
    int ch = 0;
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
        ;
}