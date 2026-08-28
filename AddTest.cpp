#include "header.h"

/**
    \details Функция AddTest копирует элементы структуры (теста) в массив тестов
*/
void AddTest(int nEquations, struct equation Tests[], struct equation *Test)
{
    assert(Tests);
    assert(Test);

    if (nEquations < MAX_TESTS - 1)
        Tests[nEquations] = *Test;  
}