#include "header.h"

void PrintOneRoot(struct equation *Eq)
{
    SlowPrintf("У уравнения один корень:\n");
	SlowPrintf(PURPLE_CNSL "a" NO_COLOR " = %lg\n", Eq -> a);
	SlowPrintf(PURPLE_CNSL "b" NO_COLOR " = %lg\n", Eq -> b);
	SlowPrintf(PURPLE_CNSL "c" NO_COLOR " = %lg\n", Eq -> c);
	SlowPrintf(PURPLE_CNSL "x" NO_COLOR " = %lg\n", Eq -> x1_Re);
	printf(PURPLE_CNSL "-----------------------------------------" NO_COLOR"\n");
}

void PrintTwoRoots(struct equation *Eq)
{
    SlowPrintf("У уравнения два вещественных корня:\n");
	SlowPrintf(PURPLE_CNSL "a" NO_COLOR " = %lg\n", Eq -> a);
	SlowPrintf(PURPLE_CNSL "b" NO_COLOR " = %lg\n", Eq -> b);
	SlowPrintf(PURPLE_CNSL "c" NO_COLOR " = %lg\n", Eq -> c);
	SlowPrintf(PURPLE_CNSL "D" NO_COLOR " = %lg\n", Eq -> D);
	SlowPrintf(PURPLE_CNSL "x1" NO_COLOR " = %lg\n", Eq -> x1_Re);
	SlowPrintf(PURPLE_CNSL "x2" NO_COLOR " = %lg\n", Eq -> x2_Re);
	printf(PURPLE_CNSL "-----------------------------------------" NO_COLOR "\n");
}

void PrintComplexRoots(struct equation *Eq)
{
    SlowPrintf("У уравнения два комплексных корня:\n");
	SlowPrintf(PURPLE_CNSL "a" NO_COLOR " = %lg\n", Eq -> a);
	SlowPrintf(PURPLE_CNSL "b" NO_COLOR " = %lg\n", Eq -> b);
	SlowPrintf(PURPLE_CNSL "c" NO_COLOR " = %lg\n", Eq -> c);
	SlowPrintf(PURPLE_CNSL "D" NO_COLOR " = %lg\n", Eq -> D);
	SlowPrintf(PURPLE_CNSL "x1" NO_COLOR ": \n");
	SlowPrintf(GREEN_CNSL "Re" NO_COLOR " =%lg\n", Eq -> x1_Re);
	SlowPrintf(GREEN_CNSL "Im" NO_COLOR " =%lg\n", Eq -> x1_Im);
	SlowPrintf(PURPLE_CNSL "x2" NO_COLOR ": \n");
	SlowPrintf(GREEN_CNSL "Re" NO_COLOR " =%lg\n", Eq -> x2_Re);
	SlowPrintf(GREEN_CNSL "Im" NO_COLOR " =%lg\n", Eq -> x2_Im);
	printf(PURPLE_CNSL "-----------------------------------------" NO_COLOR"\n");
}

void PrintInfRoots(void)
{
    SlowPrintf(RED_CNSL "ERROR: у уравнения бесконечно много корней." NO_COLOR "\n");
}

void PrintDefaultRoots(void)
{
    SlowPrintf(RED_CNSL "ERROR: некорректное квадратное уравнение." NO_COLOR "\n");
}