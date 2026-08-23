#include "header.h"

// эта функция копирует значения элементов структуры в некоторый массив 
// используется для реализации хранения истории введенных уравнений на очереди

void AddEq(int nEquations, struct equation story[], struct equation *Eq)
{
    assert(story);
    assert(Eq);

    if (nEquations < BUF_SIZE)
        story[nEquations * sizeof(equation)] = *Eq;
    else
        story[0] = *Eq;
}