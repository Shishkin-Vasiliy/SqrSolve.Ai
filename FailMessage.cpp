#include "header.h"

// печать сообщения о непройденном тесте

void FailMessage(int FailCode, struct equation *Test, struct equation RefTests[], int NumTest)
{
    assert(Test);
    assert(RefTests);

    double a = Test -> a;
    double b = Test -> b;
    double c = Test -> c;
    double D = Test -> D;
    int nRoots = Test -> nRoots;

    struct equation RefTest = RefTests[NumTest];  
    
    assert(&RefTest);

    switch(FailCode)
    {
        case CODE_ZERO:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) (NumTest / sizeof(equation)), a, b, c);
            printf("Ошибка в рассчете Дискриминанта:\n");
            printf("expected: D = %.3lg\n", RefTest.D);
            printf("got:      D = %.3lg\n\n", D);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;
        
        case CODE_ONE:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) (NumTest / sizeof(equation)), a, b, c);
            printf("Ошибка в подсчете количества корней:\n");
            printf("expected: nRoots = %d\n", RefTest.nRoots);
            printf("got:      nRoots = %d\n\n", nRoots);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;

        case CODE_TWO:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) (NumTest / sizeof(equation)), a, b, c);
            printf("Ошибка в подсчете единственного корня:\n");
            printf("expected: x = %.3lg\n", RefTest.x1 -> Re);
            printf("got:      x = %.3lg\n\n", Test -> x1 -> Re);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;

        case CODE_THREE:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) (NumTest / sizeof(equation)), a, b, c);
            printf("Ошибка в подсчете вещественных корней:\n");
            printf("expected: x1 = %.3lg\n", RefTest.x1 -> Re);
            printf("          x2 = %.3lg\n\n", RefTest.x1 -> Re);
            printf("got:      x1 = %.3lg\n", Test -> x1 -> Re);
            printf("          x2 = %.3lg\n\n", Test -> x1 -> Re); 
            printf(RED "-----------------------------------------" NO_COLOR"\n"); 
        }
        break;

        case CODE_FOUR:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) (NumTest / sizeof(equation)), a, b, c);
            printf("Ошибка в подсчете комплексных корней:\n");
            printf("expected: x1_Re = %.3lg\n", RefTest.x1 -> Re);
            printf("          x1_Im = %.3lg\n", RefTest.x1 -> Im);
            printf("          x2_Re = %.3lg\n", RefTest.x2 -> Re);
            printf("          x2_Im = %.3lg\n\n", RefTest.x2 -> Im);
            printf("got:      x1_Re = %.3lg\n", Test -> x1 -> Re);
            printf("          x1_Im = %.3lg\n", Test -> x1 -> Im);
            printf("          x2_Re = %.3lg\n", Test -> x2 -> Re);
            printf("          x2_Im = %.3lg\n\n", Test -> x2 -> Im);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;
    }
}