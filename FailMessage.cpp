#include "header.h"

// печать сообщения о непройденном тесте

void FailMessage(int FailCode, struct equation *Test, struct equation RefTests[], int NumTest)
{
    assert(Test);
    assert(RefTests);

    double a = Test -> a;
    double b = Test -> b;
    double c = Test -> c;
    double D = Test -> D;
    int nRoots = Test -> nRoots;

    struct equation RefTest = RefTests[NumTest];  
    
    assert(&RefTests[NumTest]);

    switch(FailCode)
    {
        case CODE_ZERO:
            PrintCodeZero(Test, RefTest, NumTest);
            break;
        
        case CODE_ONE:
            PrintCodeOne(Test, RefTest, NumTest);
            break;

        case CODE_TWO:
            PrintCodeTwo(Test, RefTest, NumTest);
            break;

        case CODE_THREE:
            PrintCodeThree(Test, RefTest, NumTest);
            break;

        case CODE_FOUR:
            PrintCodeFour(Test, RefTest, NumTest);
            break;

        default:
            return;
    }
}