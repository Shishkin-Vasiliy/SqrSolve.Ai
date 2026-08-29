#include "header.h"

/**
    \brief Функция обеспечивает вывод символов с задержкой для создания эффекта "печатной машинки".
    Для реализации используется список безымянных аргументов функции с переменным числом аргументов.
    Сначала этот список инициализируется, затем функция vsprintf(), используя этот список, записывает 
    еще неотформатированную строку в специальный буфер. В буфер попадает уже отформатированная строка,
    которая далее посимвольно выводится в stdout с задержкой.
*/
void SlowPrintf(const char *fmt, ...)
{
    char buf[MAX_STR] = {};
    va_list args = {};

    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    
    char *ptr = buf;

    for (; *ptr; ptr++)
    {
        printf("%c", *ptr);
        fflush(stdout);

        usleep(SLEEP_TIME);
    }
}

/**
    \brief Функция обеспечивает форматный вывод информации об уравнении и решении.
*/
void Output(struct equation *Eq)
{	
	assert(Eq);

	int nRoots = Eq -> nRoots;

	printf("\n");
	
    switch(nRoots)
		{
			case ONE_ROOT:
			{
				PrintOneRoot(Eq);
			}
				break;

			case TWO_ROOTS:
			{
				PrintTwoRoots(Eq);
			}
				break;

			case COMPLEX_ROOTS:
			{
				PrintComplexRoots(Eq);
			}
				break;

			case INF_ROOTS:
				PrintInfRoots();
				break;

			default:
				PrintDefaultRoots();
				break;
		}	
}

/**
    \brief Функция печатает в консоль краткое описание программы.
*/
void PrintDescr(void)
{ 
	printf(GREEN_CNSL "# ---------------------------------------------------------------" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "# Программа SqrSolve.Ai" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "# Решение квадратного уравнения ax^2 + bx + c = 0" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "#" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "# Пользователь вводит коэффициенты a, b, c" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "# Программа выводит решение уравнения с введенными коэффициентами" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "# А также рисует график уравнения" NO_COLOR "\n");
	SlowPrintf(GREEN_CNSL "# Для выхода введите q" NO_COLOR "\n");
	printf(GREEN_CNSL "# ---------------------------------------------------------------" NO_COLOR "\n");
	SlowPrintf("\n");
}

/**
    \brief Функция приглашает пользователя ко вводу.
*/
void Invite(void)
{
    SlowPrintf("Введите коэффициенты a, b, c (q для выхода):\n");    
}


/**
    \brief Функция вывода уравнения с одним корнем.
*/
void PrintOneRoot(struct equation *Eq)
{
    SlowPrintf("У уравнения один корень:\n");
	SlowPrintf(PURPLE_CNSL "a" NO_COLOR " = %lg\n", Eq -> a);
	SlowPrintf(PURPLE_CNSL "b" NO_COLOR " = %lg\n", Eq -> b);
	SlowPrintf(PURPLE_CNSL "c" NO_COLOR " = %lg\n", Eq -> c);
	SlowPrintf(PURPLE_CNSL "x" NO_COLOR " = %lg\n", Eq -> x1_Re);
	printf(PURPLE_CNSL "-----------------------------------------" NO_COLOR"\n");
}

/**
    \brief Функция для вывода уравнения с двумя вещественными корнями.
*/
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

/**
    \brief Функция для вывода уравнения с двумя комплексными корнями.
*/
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

/**
    \brief Функция для вывода сообщения о наличии бесконечного количнства корней.
*/
void PrintInfRoots(void)
{
    SlowPrintf(RED_CNSL "ERROR: у уравнения бесконечно много корней." NO_COLOR "\n");
}

/**
    \brief Функция для вывода сообщения о некорректности введенных коэффициентов.
*/
void PrintDefaultRoots(void)
{
    SlowPrintf(RED_CNSL "ERROR: некорректное квадратное уравнение." NO_COLOR "\n");
}


/**
    \brief Функция для вывода сообщения об ошибке в тесте с номером 0.
*/
void PrintCodeZero(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в рассчете Дискриминанта:\n");
    printf("expected: D = %lg\n", RefTest.D);
    printf("got:      D = %lg\n\n", Test -> D);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

/**
    \brief Функция для вывода сообщения об ошибке в тесте с номером 1.
*/
void PrintCodeOne(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", (int) NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в подсчете количества корней:\n");
    printf("expected: nRoots = %d\n", RefTest.nRoots);
    printf("got:      nRoots = %d\n\n", Test -> nRoots);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

/**
    \brief Функция для вывода сообщения об ошибке в тесте с номером 2.
*/
void PrintCodeTwo(struct equation *Test, struct equation RefTest, int NumTest)
{
    printf(RED_CNSL "Test %d FAILED:" NO_COLOR " a = %lg, b = %lg, c = %lg\n", NumTest, Test -> a, Test -> b, Test -> c);
    printf("Ошибка в подсчете единственного корня:\n");
    printf("expected: x = %lg\n", RefTest.x1_Re);
    printf("got:      x = %lg\n\n", Test -> x1_Re);
    printf(RED_CNSL "-----------------------------------------" NO_COLOR"\n");
}

/**
    \brief Функция для вывода сообщения об ошибке в тесте с номером 3.
*/
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

/**
    \brief Функция для вывода сообщения об ошибке в тесте с номером 4.
*/
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
