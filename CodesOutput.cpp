#include "header.h"

void PrintCodeZero(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в рассчете Дискриминанта:\n");
    printf("expected: D = %lg\n", RefTest.D);
    printf("got:      D = %lg\n\n", Test -> D);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

void PrintCodeOne(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в подсчете количества корней:\n");
    printf("expected: nRoots = %d\n", RefTest.nRoots);
    printf("got:      nRoots = %d\n\n", Test -> nRoots);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

void PrintCodeTwo(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в подсчете единственного корня:\n");
    printf("expected: x = %lg\n", RefTest.x1_Re);
    printf("got:      x = %lg\n\n", Test -> x1_Re);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

void PrintCodeThree(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в подсчете вещественных корней:\n");
    printf("expected: x1 = %lg\n", RefTest.x1_Re);
    printf("          x2 = %lg\n\n", RefTest.x2_Re);
    printf("got:      x1 = %lg\n", Test -> x1_Re);
    printf("          x2 = %lg\n\n", Test -> x2_Re); 
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

void PrintCodeFour(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в подсчете комплексных корней:\n");
    printf("expected: x1_Re = %lg\n", RefTest.x1_Re);
    printf("          x1_Im = %lg\n", RefTest.x1_Im);
    printf("          x2_Re = %lg\n", RefTest.x2_Re);
    printf("          x2_Im = %lg\n\n", RefTest.x2_Im);
    printf("got:      x1_Re = %lg\n", Test -> x1_Re);
    printf("          x1_Im = %lg\n", Test -> x1_Im);
    printf("          x2_Re = %lg\n", Test -> x2_Re);
    printf("          x2_Im = %lg\n\n", Test -> x2_Im);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}