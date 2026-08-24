#include "header.h"

long unsigned int Rand(long unsigned int Next)
{
    Next = Next * 1103515245 + 12345;
    return (Next / 65536) % 32768;
}

void PrintTokens(long unsigned int *Tokens)
{
    long unsigned int Temp = *Tokens;
	*Tokens = Rand(Temp);
	printf("У вас осталось %lu токенов.\n\n\n", Temp);
}
 

