#include "header.h"
/**
	\brief Очищает буфер ввода.
	\param[out] garbage
	Функция устанавливает garbage в 1, если после введенных коэффициентов есть мусор, например 1 2 4g
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
	\param[in] file
*/
void FileClearBuf(FILE *file)
{
    assert(file);
    
    int ch = 0;
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
        ;
}