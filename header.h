#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <assert.h>
#include <float.h>
#include <time.h>
#include <cstddef>
#include <ctype.h>
#include "raylib.h"

#define	RED 	 "\033[31m"
#define	GREEN 	 "\033[32m"
#define	PURPLE   "\033[35m"
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

struct Flags {
	int User;
	int Test;
	int Graph;
};

const int EQ_ARG_NUM  = 9;
const int FOUR_DIGITS = 4;

const int BUF_SIZE = 4;
const int MAX_TESTS = 6;

const int MAX_POINTS = 1200;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int X_ZERO = SCREEN_WIDTH / 2;
const int Y_ZERO = SCREEN_HEIGHT / 2;
const int LINE_THICKNESS = 5;
const int AX_THICKNESS = 2;

enum NUM_ROOTS {
	ONE_ROOT = 1,
	TWO_ROOTS = 2,
	COMPLEX_ROOTS = 3,
	INF_ROOTS = -1,
};

enum NUM_CODE {
	PASS = -1,
	CODE_ZERO = 0,
	CODE_ONE = 1,
	CODE_TWO = 2,
	CODE_THREE = 3,
	CODE_FOUR = 4
};

void CmdFlag(struct Flags *Flags, int argc, char *argv[]);   
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

void PrintOneRoot(struct equation *Eq);
void PrintTwoRoots(struct equation *Eq);
void PrintComplexRoots(struct equation *Eq);
void PrintInfRoots(void);
void PrintDefaultRoots(void);

void PrintCodeZero(struct equation *Test, struct equation RefTest, int numTest);
void PrintCodeOne(struct equation *Test, struct equation RefTest, int numTest);
void PrintCodeTwo(struct equation *Test, struct equation RefTest, int numTest);
void PrintCodeThree(struct equation *Test, struct equation RefTest, int numTest);
void PrintCodeFour(struct equation *Test, struct equation RefTest, int numTest);

void TestMain(struct equation RefTests[], struct equation Tests[]);
void AddTest(int nEquations, struct equation Tests[], struct equation *Test);
void GetTest(struct equation *Test, struct equation Tests[], FILE *file, int nTests);
void ReadTests(struct equation Tests[], struct equation RefTests[]);
NUM_CODE TestFailCode(struct equation *Test,  struct equation RefTests[], int NumTest);
void FailMessage(int FailCode, struct equation *Test, struct equation RefTest[], int NumTest);

void DrawPoints(float X[], float Y[]);
void DrawLinear(double b, double c, float X[]);
void DrawParabola(double a, double b, double c, float X[]);
void DrawMain(struct equation Eq);
void DrawAxes(void);

void PrintTokens(long unsigned int *Tokens);
long unsigned int Rand(long unsigned int Next);

#endif