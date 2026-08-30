#include "header.h"

/**
    \brief Функция для генерации псевдослучайных чисел.
    \param[in] Next
*/
long unsigned int Rand(long unsigned int Next)
{
    Next = Next * 1103515245 + 12345;
    return (Next / 65536) % 32768;
}

/**
    \brief Функция для вывода информации о количестве оставшихся токенов.
    \param[in] Tokens
*/
void PrintTokens(long unsigned int *Tokens)
{
    long unsigned int Temp = *Tokens;
	*Tokens = Rand(Temp);
	printf("У вас осталось %lu токенов.\n\n\n", Temp);
}
 

