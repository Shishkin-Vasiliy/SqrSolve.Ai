#include "header.h"

/**
	main программы SqrSolve.Ai.
*/
int main(int argc, char *argv[])
{
	
	PrintDescr();                          

	struct equation story[STORY_SIZE] = {};
	int nEquations = 0;                                      

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

	struct Flags Flags = {
		.User = 0,
		.Test = 0,
		.Graph = 0
	};

	CmdFlag(&Flags, argc, argv);

	if (Flags.Test)
	{
		struct equation RefTests[MAX_TESTS] = {}; 
		struct equation Tests[MAX_TESTS] = {};

	   	TestMain(RefTests, Tests);

		if (!Flags.User)
			return 0;
	}
	
	Invite();

	bool flag = 0;      
	long unsigned int Tokens = 38494;

	while (GetCoeff(&Eq) != 0) 
	{
		SqrSolve(&Eq);
		SetFlag(&nEquations, &flag);
		AddEq(nEquations, story, &Eq);
		nEquations++;
		Output(&Eq);  
		PrintTokens(&Tokens); 
		
		if (Flags.Graph)
			DrawMain(Eq);            
	}
 
	PrintStory(nEquations, story, flag);

	return 0;	
}
