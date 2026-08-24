#include "header.h"

// управляющая программа тестирования

void TestMain(struct equation RefTests[], struct equation Tests[])
{
    assert(RefTests);
    assert(Tests);

    int Code = 0;                 
    int NumFails = 0;             

    printf("Тестирование программы:\n\n");
    printf("...\n");
    ReadTests(Tests, RefTests);   

    for (int i = 0; i < MAX_TESTS; i++)
    {
        Code = TestFailCode(&Tests[i], RefTests, i); 

        if (Code >= 0)
            NumFails++;
        
        FailMessage(Code, &Tests[i], RefTests, i);
    }
    printf("\nТестирование завершено, пройдено" GREEN " %d" NO_COLOR " тестов из %d\n\n", MAX_TESTS - NumFails, MAX_TESTS);
}