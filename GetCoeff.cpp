#include "header.h"

/** 
	\brief Функция, считывающая коэффициенты из терминала в структуру уравнения.
	Переменная ThreePtr является индикатором для цикла while, нужно ли продолжать чтение коэффициентов:
	Если все три коэффициента прочитаны корректно (трех-очковый), то цикл while завершает работу.
	Иначе запускается scanf(). Если он ничего не прочитал, то проверяем с помощью getchar() не введен
	ли символ 'q', указывающий на выход из программы. Если это не он, то возвращаем прочитанный символ в 
	буфер stdin, чтобы избежать ситуаций типа g\n, где w прочитана с помощью getchar(), в ClearBuf()
	попадает только символ '\n', что моментально завершает очистку буфера, которая отработала некорректно. 
*/

int GetCoeff(struct equation *Eq)
{
	assert(Eq);

	const int NUM_COEFFS = 3;
	int ch = 0;
	int state = 0;
	int garbage = 0;
	int ThreePtr = 0;
//
//while ((state = scanf("%lg %lg %lg", &(Eq -> a), &(Eq -> b), &(Eq -> c))) != NUM_COEFFS)
//{
//    if ((ch = getchar()) == 'q')
//	    return 0;
//	
//	ClearBuf();	  	
//}
//ClearBuf();
	
	while (!ThreePtr)
	{
		Invite();

		state = scanf("%lg %lg %lg", &(Eq -> a), &(Eq -> b), &(Eq -> c));

		if (state == 0)
		{
			if ((ch = getchar()) == 'q')
				return 0;
		} 

		garbage = ClearBuf();

		ThreePtr = (state == NUM_COEFFS && garbage == 0 && isfinite(Eq -> a) && isfinite(Eq -> b) && isfinite(Eq -> c));

		if (!ThreePtr)
			Damn();
	}
	return state;
}

