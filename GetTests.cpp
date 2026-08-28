#include "header.h"

const char *TestsFile = "Tests.txt";
const char *RefTestsFile = "RefTests.txt";

void GetTest(struct equation *Test, struct equation Tests[], FILE *file, int nTests)
{
    assert(Test);
    assert(Tests);
    assert(file);

    if (nTests < MAX_TESTS && (fscanf(file, "%lg %lg %lg %lg %d %lg %lg %lg %lg", &(Test -> a), &(Test -> b), &(Test -> c), &(Test -> D), &(Test -> nRoots), &(Test -> x1_Re), &(Test -> x1_Im), &(Test -> x2_Re), &(Test -> x2_Im))) == EQ_ARG_NUM)
    {
    AddTest(nTests, Tests, Test);       
    FileClearBuf(file);
    }
}

void ReadTests(struct equation Tests[], struct equation RefTests[])
{
    int nTests = 0;

    FILE *TestPtr = fopen(TestsFile, "r");
    FILE *RefTestPtr = fopen(RefTestsFile, "r");

    assert(TestPtr);
    assert(RefTestPtr);

    equation Test = {};
    
    for (int i = 0; i < MAX_TESTS; i++)
    {
        Test = {
        .a = NAN,
        .b = NAN,
        .c = NAN,
        .D = NAN,
        .nRoots = -2,
        .x1_Re = NAN,
        .x1_Im = NAN,
        .x2_Re = NAN,
        .x2_Im = NAN,
        };
        GetTest(&Test, RefTests, RefTestPtr, nTests);
        SqrSolve(&Test);
        nTests++;
    }

    nTests = 0;

    for (int i = 0; i < MAX_TESTS; i++)
    {
        Test = {
        .a = NAN,
        .b = NAN,
        .c = NAN,
        .D = NAN,
        .nRoots = -2,
        .x1_Re = NAN,
        .x1_Im = NAN,
        .x2_Re = NAN,
        .x2_Im = NAN,
        };
        GetTest(&Test, Tests, TestPtr, nTests);  
        SqrSolve(&Test);
        nTests++;
    }

    fclose(TestPtr);
}

