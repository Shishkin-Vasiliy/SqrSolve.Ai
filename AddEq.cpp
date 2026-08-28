#include "header.h"

/**
    \details Функция AddEq копирует структуру уравнения в массив story для дальнейшего вывода истории запросов.
             Выводятся последние STORY_SIZE запросов.
             Ветка else в этой функции нужна для добавления элемента в конец массива, так как это нужно для реализации
             вывода истории в порядке очереди (более подробный алгоритм описан в описании функции SetFlag)
*/
void AddEq(int nEquations, struct equation story[], struct equation *Eq)
{
    assert(story);
    assert(Eq);

    if (nEquations < STORY_SIZE)
        story[nEquations] = *Eq;
    else
        story[0] = *Eq;    
}