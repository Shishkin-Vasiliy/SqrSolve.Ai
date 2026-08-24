#include "header.h"

void PrintOne(struct equation *Eq)
{
    printf("У уравнения один корень:\n");
	printf(PURPLE "a" NO_COLOR " = %lg\n", Eq -> a);
	printf(PURPLE "b" NO_COLOR " = %lg\n", Eq -> b);
	printf(PURPLE "c" NO_COLOR " = %lg\n", Eq -> c);
	printf(PURPLE "x" NO_COLOR " = %lg\n", Eq -> x1_Re);
	printf(PURPLE "-----------------------------------------" NO_COLOR"\n");
}

void PrintTwo(struct equation *Eq)
{
    printf("У уравнения два вещественных корня:\n");
	printf(PURPLE "a" NO_COLOR " = %lg\n", Eq -> a);
	printf(PURPLE "b" NO_COLOR " = %lg\n", Eq -> b);
	printf(PURPLE "c" NO_COLOR " = %lg\n", Eq -> c);
	printf(PURPLE "D" NO_COLOR " = %lg\n", Eq -> D);
	printf(PURPLE "x1" NO_COLOR " = %lg\n", Eq -> x1_Re);
	printf(PURPLE "x2" NO_COLOR " = %lg\n", Eq -> x2_Re);
	printf(PURPLE "-----------------------------------------" NO_COLOR "\n");
}

void PrintComplex(struct equation *Eq)
{
    printf("У уравнения два комплексных корня:\n");
	printf(PURPLE "a" NO_COLOR " = %lg\n", Eq -> a);
	printf(PURPLE "b" NO_COLOR " = %lg\n", Eq -> b);
	printf(PURPLE "c" NO_COLOR " = %lg\n", Eq -> c);
	printf(PURPLE "D" NO_COLOR " = %lg\n", Eq -> D);
	printf(PURPLE "x1" NO_COLOR ": \n");
	printf(GREEN "Re" NO_COLOR " =%lg\n", Eq -> x1_Re);
	printf(GREEN "Im" NO_COLOR " =%lg\n", Eq -> x1_Im);
	printf(PURPLE "x2" NO_COLOR ": \n");
	printf(GREEN "Re" NO_COLOR " =%lg\n", Eq -> x2_Re);
	printf(GREEN "Im" NO_COLOR " =%lg\n", Eq -> x2_Im);
	printf(PURPLE "-----------------------------------------" NO_COLOR"\n");
}

void PrintInf(void)
{
    printf(RED "ERROR: у уравнения бесконечно много корней." NO_COLOR "\n");
}

void PrintDefault(void)
{
    printf(RED "ERROR: некорректное квадратное уравнение." NO_COLOR "\n");
}