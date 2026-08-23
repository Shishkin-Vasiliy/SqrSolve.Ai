#include "header.h"

void PrintStory(int nEquations, struct equation story[], int flag)
{
    assert(story);

    printf("\n");
    printf("История решений:\n");
    printf("\n");
    
    int i = (nEquations) * sizeof(equation);
    int j = 0;

    if (flag)
    {
        for (j = i; j < BUF_SIZE * sizeof(equation);)
        {
                Output(&story[j]);
                j = j + sizeof(equation);
        }

        for (j = 0; j < i;)
        {
            Output(&story[j]);
            j = j + sizeof(equation);
        }   
    }

    // вторая проверка в следующем цикле нужна, чтобы не выводить еще не введенные уравнения
    // если их введено меньше размера буфера
    // (иначе программа выведет ERROR: некорректное квадратное уравнение)
    else
        for (j = 0; j < BUF_SIZE * sizeof(equation) && j < i;)
        {
            Output(&story[j]);
            j = j + sizeof(equation);
        }
    
    printf("\n");
    printf(GREEN "-----------------------------------------" NO_COLOR "\n");
}