#include "header.h"

void TestMain(struct equation RefTests[], struct equation Tests[])
{
    assert(RefTests);
    assert(Tests);

    int Code = 0;                 
    int NumFails = 0;             

    SlowPrintf("Тестирование программы:\n\n");
    SlowPrintf("...\n");
    ReadTests(Tests, RefTests);   

    for (int i = 0; i < MAX_TESTS; i++)
    {
        Code = TestFailCode(&Tests[i], RefTests, i); 

        if (Code >= 0)
            NumFails++;
        
        FailMessage(Code, &Tests[i], RefTests, i);
    }
    SlowPrintf("\nТестирование завершено, пройдено" GREEN_CNSL " %d" NO_COLOR " тестов из %d\n\n", MAX_TESTS - NumFails, MAX_TESTS);
}

