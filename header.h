#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <assert.h>
#include <float.h>
#include <cstddef>

#define	RED "\033[31m"
#define	GREEN "\033[32m"
#define	PURPLE "\033[35m"
#define	NO_COLOR "\033[0m"

struct root {
	double Re;
	double Im;
};

struct equation {
	double a;
	double b;
	double c;
	double D;
	int nRoots;
	struct root *x1;
	struct root *x2;
};

#define	BUF_SIZE 3
#define	MAXLEN (BUF_SIZE * sizeof(equation))
#define	MAX_TESTS 2
#define TESTS_BUF (MAX_TESTS * sizeof(equation))

enum NUM_ROOTS {
	ONE_ROOT = 1,
	TWO_ROOTS = 2,
	COMPLEX_ROOTS = 3,
	INF_ROOTS = -1
};

enum NUM_CODE {
	PASS = -1,
	CODE_ZERO = 0,
	CODE_ONE = 1,
	CODE_TWO = 2,
	CODE_THREE = 3,
	CODE_FOUR = 4
};

void CmdFlag(int *TestFlag, int *UserFlag, int argc, char *argv[]);   
void PrintDescr(void);                                 
void Invite(void);									   
void SqrSolve(struct equation *Eq);                    
void LnrSolve(struct equation *Eq);					   
int GetKoeff(struct equation *Eq);					   
void Discr(struct equation *Eq);                       
void Output(struct equation *Eq);                      
void ClearBuf(void);								   
int Cmp(double a, double b);
void AddEq(int nEquations, struct equation story[], struct equation *Eq);
void PrintStory(int nEquations, struct equation story[], int flag);
int SetFlag(int nEquations);
void FileClearBuf(FILE *file);

int TestMain(struct equation RefTests[], struct equation Tests[]);
void GetTest(struct equation *Test, struct equation Tests[], FILE *file, int nTests);
void ReadTests(struct equation Tests[], struct equation RefTests[]);
NUM_CODE TestFailCode(struct equation *Test,  struct equation RefTests[], int NumTest);
void FailMessage(int FailCode, struct equation *Test, struct equation RefTest[], int NumTest);

int Rand(long unsigned int Next);

#endif