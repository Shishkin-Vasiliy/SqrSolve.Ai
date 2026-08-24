#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <assert.h>
#include <float.h>
#include <time.h>
#include <cstddef>

#define	RED "\033[31m"
#define	GREEN "\033[32m"
#define	PURPLE "\033[35m"
#define	NO_COLOR "\033[0m"

struct equation {
	double a;
	double b;
	double c;
	double D;
	int nRoots;
	double x1_Re;
	double x1_Im;
	double x2_Re;
	double x2_Im;
};

#define EQ_ARG_NUM 9
#define FOUR_DIGITS 4

#define	BUF_SIZE 4
#define	MAX_TESTS 5 

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
int Cmp(double a, double b, int Accuracy);
void AddEq(int nEquations, struct equation story[], struct equation *Eq);
void PrintStory(int nEquations, struct equation story[], int flag);
void SetFlag(int *nEquations, int *flag);
void FileClearBuf(FILE *file);

void PrintOne(struct equation *Eq);
void PrintTwo(struct equation *Eq);
void PrintComplex(struct equation *Eq);
void PrintInf(void);
void PrintDefault(void);

void TestMain(struct equation RefTests[], struct equation Tests[]);
void GetTest(struct equation *Test, struct equation Tests[], FILE *file, int nTests);
void ReadTests(struct equation Tests[], struct equation RefTests[]);
NUM_CODE TestFailCode(struct equation *Test,  struct equation RefTests[], int NumTest);
void FailMessage(int FailCode, struct equation *Test, struct equation RefTest[], int NumTest);

void PrintTokens(long unsigned int *Tokens);
long unsigned int Rand(long unsigned int Next);

#endif