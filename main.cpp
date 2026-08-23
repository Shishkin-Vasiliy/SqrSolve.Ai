#include "header.h"

int main(int argc, char *argv[])
{
	long unsigned int Tokens = 38494;

	PrintDescr();                          // описание программы

	struct equation story[MAXLEN] = {};
	int nEquations = 0;                    // количество решенных уравнений
	int NumFails = 0;                      // количество непройденных тестов
	int TestFlag = 0;                	   // флаг для запуска тестирования 
	int UserFlag = 0;                      // флаг для запуска решения уравнений

	struct root x1 = {};
	struct root x2 = {};
	struct equation Eq = {};

	Eq.x1 = &x1;
	Eq.x2 = &x2;

	CmdFlag(&TestFlag, &UserFlag, argc, argv);

	if (TestFlag)
	{
		struct equation RefTests[TESTS_BUF] = {}; 
		struct equation Tests[TESTS_BUF] = {};

	    NumFails = TestMain(RefTests, Tests);

		if (!UserFlag)
			return 0;
	}
	
	Invite();

	int flag = 0;      
	long unsigned int Temp = 0;

	while (GetKoeff(&Eq) != 0)
	{
		SqrSolve(&Eq);
		flag = SetFlag(nEquations);
		AddEq(nEquations, story, &Eq);
		nEquations++;
		Output(&Eq);  
		Temp = Tokens;
		Tokens = Rand(Temp);
		printf("У вас осталось %ld токенов.\n\n\n", Tokens);             
	}

	PrintStory(nEquations, story, flag);

	return 0;	
}
