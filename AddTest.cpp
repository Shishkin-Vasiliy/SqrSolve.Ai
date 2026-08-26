#include "header.h"

void AddTest(int nEquations, struct equation Tests[], struct equation *Test)
{
    assert(Tests);
    assert(Test);

    if (nEquations < BUF_SIZE)
        Tests[nEquations] = *Test;  
}