#include "header.h"

// эта функция возвращает код ошибки 

NUM_CODE TestFailCode(struct equation *Test, struct equation RefTests[], int NumTest)
{
    assert(Test);
    assert(RefTests);

    SqrSolve(Test);

    // данные теста
    double a = Test -> a;
    double b = Test -> b;
    double c = Test -> c;
    double D = Test -> D;
    int nRoots = Test -> nRoots;

    double x1_Re = Test -> x1 -> Re;
    double x1_Im = Test -> x1 -> Im;

    double x2_Re = Test -> x2 -> Re;
    double x2_Im = Test -> x2 -> Im;
    //------------------------------        

    struct equation RefTest = RefTests[NumTest];   // выбираем нужный тест для сравнения 
                                                   // с теми же a, b, c
    // данные образца
    int nRoots_ref = RefTest.nRoots;

    double D_ref = RefTest.D;

    double x1_Re_ref = RefTest.x1->Re;
    double x1_Im_ref = RefTest.x1->Im;
    
    double x2_Re_ref = RefTest.x2->Re;
    double x2_Im_ref = RefTest.x2->Im;
    //--------------------------------

    if (D != D_ref)
        return CODE_ZERO;
    else if (nRoots != nRoots_ref)
        return CODE_ONE;
    
    if (nRoots == ONE_ROOT)
    {
        if (x1_Re != x1_Re_ref)
            return CODE_TWO;
    }
    else if (nRoots == TWO_ROOTS)
    {
        if (x1_Re != x1_Re_ref || x2_Re != x2_Re_ref

        && ~(x1_Re == x2_Re_ref && x2_Re == x1_Re_ref))
            return CODE_THREE;
    }
    else if (nRoots == COMPLEX_ROOTS)
    {
        if (x1_Re != x1_Re_ref || x1_Im != x1_Im_ref
        ||  x2_Re != x2_Re_ref || x2_Im != x2_Im_ref

        &&  ~(x1_Re == x2_Re_ref && x2_Re == x1_Re_ref
        &&    x1_Im == x2_Im_ref && x2_Im == x1_Im_ref))
            return CODE_FOUR;
    }
    return PASS;
}

