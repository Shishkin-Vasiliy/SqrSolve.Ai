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
    
    assert(&RefTests[NumTest]);

    switch(FailCode)
    {
        case CODE_ZERO:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, a, b, c);
            printf("Ошибка в рассчете Дискриминанта:\n");
            printf("expected: D = %lg\n", RefTest.D);
            printf("got:      D = %lg\n\n", D);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;
        
        case CODE_ONE:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) NumTest, a, b, c);
            printf("Ошибка в подсчете количества корней:\n");
            printf("expected: nRoots = %d\n", RefTest.nRoots);
            printf("got:      nRoots = %d\n\n", nRoots);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;

        case CODE_TWO:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, a, b, c);
            printf("Ошибка в подсчете единственного корня:\n");
            printf("expected: x = %lg\n", RefTest.x1_Re);
            printf("got:      x = %lg\n\n", Test -> x1_Re);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;

        case CODE_THREE:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, a, b, c);
            printf("Ошибка в подсчете вещественных корней:\n");
            printf("expected: x1 = %lg\n", RefTest.x1_Re);
            printf("          x2 = %lg\n\n", RefTest.x2_Re);
            printf("got:      x1 = %lg\n", Test -> x1_Re);
            printf("          x2 = %lg\n\n", Test -> x2_Re); 
            printf(RED "-----------------------------------------" NO_COLOR"\n"); 
        }
        break;

        case CODE_FOUR:
        {
            printf(RED "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, a, b, c);
            printf("Ошибка в подсчете комплексных корней:\n");
            printf("expected: x1_Re = %lg\n", RefTest.x1_Re);
            printf("          x1_Im = %lg\n", RefTest.x1_Im);
            printf("          x2_Re = %lg\n", RefTest.x2_Re);
            printf("          x2_Im = %lg\n\n", RefTest.x2_Im);
            printf("got:      x1_Re = %lg\n", Test -> x1_Re);
            printf("          x1_Im = %lg\n", Test -> x1_Im);
            printf("          x2_Re = %lg\n", Test -> x2_Re);
            printf("          x2_Im = %lg\n\n", Test -> x2_Im);
            printf(RED "-----------------------------------------" NO_COLOR"\n");
        }
        break;

        default:
            return;
    }
}