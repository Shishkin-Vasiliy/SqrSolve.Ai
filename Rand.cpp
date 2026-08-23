#include "header.h"

int Rand(long unsigned int Next)
{
    Next = Next * 1103515245 + 12345;
    return (unsigned int)(Next / 65536) % 32768;
}
 

