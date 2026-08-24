#include "header.h"

void AddEq(int nEquations, struct equation story[], struct equation *Eq)
{
    assert(story);
    assert(Eq);

    if (nEquations < BUF_SIZE)
        story[nEquations] = *Eq;
    else
        story[0] = *Eq;    
}