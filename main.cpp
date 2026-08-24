#include "header.h"

int main(int argc, char *argv[])
{
	long unsigned int Tokens = 38494; // todo  // no

	PrintDescr();                          

	struct equation story[BUF_SIZE] = {};
	int nEquations = 0;                    
	int TestFlag = 0;                	   
	int UserFlag = 0;                     

	struct equation Eq = {
		.a = NAN,
		.b = NAN,
		.c = NAN,
		.D = NAN,
		.nRoots = -2,
		.x1_Re = NAN,
		.x1_Im = NAN,
		.x2_Re = NAN,
		.x2_Im = NAN
	};

	CmdFlag(&TestFlag, &UserFlag, argc, argv);

	if (TestFlag)
	{
		struct equation RefTests[MAX_TESTS] = {}; 
		struct equation Tests[MAX_TESTS] = {};

	   	TestMain(RefTests, Tests);

		if (!UserFlag)
			return 0;
	}
	
	Invite();

	int flag = 0;      
	long unsigned int Temp = 0;

	while (GetKoeff(&Eq) != 0) // Todo
	{
		SqrSolve(&Eq);
		SetFlag(&nEquations, &flag);
		AddEq(nEquations, story, &Eq);
		nEquations++;
		Output(&Eq);  
		Temp = Tokens;
		Tokens = Rand(Temp);
		printf("У вас осталось %lu токенов.\n\n\n", Temp);             
	}

	PrintStory(nEquations, story, flag);

	return 0;	
}
