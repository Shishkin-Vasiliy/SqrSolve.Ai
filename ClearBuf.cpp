#include "header.h"
/**
	\brief Очищает буфер ввода.
*/
void ClearBuf(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n')
		;
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