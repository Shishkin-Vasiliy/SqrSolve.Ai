
#include "header.h"

const char *TestsFile = "Tests.txt";
const char *RefTestsFile = "RefTests.txt";

// GetTest() получает из файла строку (Тест) с элементами структуры equation
// и записывает эти данные в массив Тестов с помощью AddEq()

void GetTest(struct equation *Test, struct equation Tests[], FILE *file, int nTests)
{
    assert(Test);
    assert(file);

    if (nTests < MAX_TESTS && (fscanf(file, "%lg%lg%lg%lg%d%lg%lg%lg%lg", &(Test -> a), &(Test -> b), &(Test -> c), &(Test -> D), &(Test -> nRoots), &(Test -> x1 -> Re), &(Test -> x1 -> Im), &(Test -> x2 -> Re), &(Test -> x2 -> Im))) != EOF)
    {
    AddEq(nTests, Tests, Test);
    FileClearBuf(file);
    }
}
 

// ReadTests() в двух циклах вызывает GetTest для заполнения двух 
// массивов с тестами (реальные и эталонные)

void ReadTests(struct equation Tests[], struct equation RefTests[])
{
    int nTests = 0;
    FILE *TestPtr = fopen(TestsFile, "r");
    FILE *RefTestPtr = fopen(RefTestsFile, "r");

    assert(TestPtr);
    assert(RefTestPtr);

    root x1 = {};
    root x2 = {};

    equation Test = {};
    Test.x1 = &x1;
    Test.x2 = &x2;
    
    for (int i = 0; i < MAX_TESTS; i++)
    {
        GetTest(&Test, Tests, TestPtr, nTests);      
        nTests++;
    }

    for (int i = 0, nTests = 0; i < MAX_TESTS; i++)
    {
        GetTest(&Test, RefTests, RefTestPtr, nTests);
        nTests++;
    }

    fclose(TestPtr);
}

