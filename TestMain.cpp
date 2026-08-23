#include "header.h"

// управляющая программа тестирования

int TestMain(struct equation RefTests[], struct equation Tests[])
{
    assert(RefTests);
    assert(Tests);

    int Code = 0;                 // код ошибки
    int NumFails = 0;             // число непройденных тестов

    printf("Тестирование программы:\n\n");
    ReadTests(Tests, RefTests);    

    for (int i = 0; i < TESTS_BUF; i = i + sizeof(equation))
    {
        Code = TestFailCode(&Tests[i], RefTests, i);     
        if (Code >= 0)
            NumFails++;

        FailMessage(Code, &Tests[i], RefTests, i);
    }
    printf("\nТестирование завершено, пройдено" GREEN " %d" NO_COLOR " тестов из %d\n\n", MAX_TESTS - NumFails, MAX_TESTS);
// color
    return NumFails;
}