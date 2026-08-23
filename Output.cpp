#include "header.h"

void Output(struct equation *Eq)
{
	assert(Eq);

	int nRoots = Eq -> nRoots;
    switch(nRoots)
		{
			case ONE_ROOT:
			{
				printf("У уравнения один корень:\n");
				printf(PURPLE "a" NO_COLOR " = %.3lg\n", Eq -> a);
				printf(PURPLE "b" NO_COLOR " = %.3lg\n", Eq -> b);
				printf(PURPLE "x" NO_COLOR " = %.3lg\n", Eq -> x1 -> Re);
				printf(PURPLE "-----------------------------------------" NO_COLOR"\n");
			}
				break;

			case TWO_ROOTS:
			{
				printf("У уравнения два вещественных корня:\n");
				printf(PURPLE "a" NO_COLOR " = %.3lg\n", Eq -> a);
				printf(PURPLE "b" NO_COLOR " = %.3lg\n", Eq -> b);
				printf(PURPLE "c" NO_COLOR " = %.3lg\n", Eq -> c);
				printf(PURPLE "D" NO_COLOR " = %.3lg\n", Eq -> D);
				printf(PURPLE "x1" NO_COLOR " = %.3lg\n", Eq -> x1 -> Re);
				printf(PURPLE "x2" NO_COLOR " = %.3lg\n", Eq -> x2 -> Re);
				printf(PURPLE "-----------------------------------------" NO_COLOR "\n");
			}
				break;

			case COMPLEX_ROOTS:
			{
				printf("У уравнения два комплексных корня:\n");
				printf(PURPLE "a" NO_COLOR " = %.3lg\n", Eq -> a);
				printf(PURPLE "b" NO_COLOR " = %.3lg\n", Eq -> b);
				printf(PURPLE "c" NO_COLOR " = %.3lg\n", Eq -> c);
				printf(PURPLE "D" NO_COLOR " = %.3lg\n", Eq -> D);
				printf(PURPLE "x1" NO_COLOR ":\n");
				printf(GREEN "Re" NO_COLOR " =%.3lg\n", Eq -> x1 -> Re);
				printf(GREEN "Im" NO_COLOR " =%.3lg\n", Eq -> x1 -> Im);
				printf(PURPLE "x2" NO_COLOR ":\n");
				printf(GREEN "Re" NO_COLOR " =%.3lg\n", Eq -> x2 -> Re);
				printf(GREEN "Im" NO_COLOR " =%.3lg\n", Eq -> x2 -> Im);
				printf(PURPLE "-----------------------------------------" NO_COLOR"\n");
			}
				break;

			case INF_ROOTS:
				printf(RED "ERROR: у уравнения бесконечно много корней." NO_COLOR "\n");
				break;

			default:
				printf(RED "ERROR: некорректное квадратное уравнение." NO_COLOR "\n");
				break;
		}	
}
