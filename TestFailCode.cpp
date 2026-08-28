#include "header.h"

NUM_CODE TestFailCode(struct equation *Test, struct equation RefTests[], int NumTest)
{
    assert(Test);
    assert(RefTests);

    SqrSolve(Test);

    double D = Test -> D;
    int nRoots = Test -> nRoots;

    double x1_Re = Test -> x1_Re;
    double x1_Im = Test -> x1_Im;

    double x2_Re = Test -> x2_Re;
    double x2_Im = Test -> x2_Im;


    struct equation RefTest = RefTests[NumTest];   

    assert(0 <= NumTest && NumTest < MAX_TESTS);
 
    int nRoots_ref = RefTest.nRoots;

    double D_ref = RefTest.D;

    double x1_Re_ref = RefTest.x1_Re;
    double x1_Im_ref = RefTest.x1_Im;
    
    double x2_Re_ref = RefTest.x2_Re;
    double x2_Im_ref = RefTest.x2_Im;

    
    if (Cmp(D, D_ref, PRECISION) != 0 && !(isnan(D) && isnan(D_ref)))
        return CODE_ZERO;
    
    else if (nRoots != nRoots_ref && !(isnan(nRoots) && isnan(nRoots_ref)))
        return CODE_ONE;
    
    if (nRoots == ONE_ROOT)
    {
        if (Cmp(x1_Re, x1_Re_ref, PRECISION) != 0 && !(isnan(x1_Re) && isnan(x1_Re_ref)))
            return CODE_TWO;
    }

    else if (nRoots == TWO_ROOTS)
    {
        if (Cmp(x1_Re, x1_Re_ref, PRECISION) != 0 || (Cmp(x2_Re, x2_Re_ref, PRECISION) != 0)
        && (!(isnan(x1_Re) && isnan(x1_Re_ref)) 
        &&  !(isnan(x2_Re) && isnan(x2_Re_ref))))
            return CODE_THREE;
    }

    else if (nRoots == COMPLEX_ROOTS)
    {
        if ((Cmp(x1_Re, x1_Re_ref, PRECISION) != 0) || (Cmp(x1_Im, x1_Im_ref, PRECISION) != 0)
        ||  (Cmp(x2_Re, x2_Re_ref, PRECISION) != 0) || (Cmp(x2_Im, x2_Im_ref, PRECISION) != 0)
        
        &&  !(isnan(x1_Re) && isnan(x1_Re_ref))
        &&  !(isnan(x1_Im) && isnan(x1_Im_ref))

        &&  !(isnan(x2_Re) && isnan(x2_Re_ref))
        &&  !(isnan(x2_Im) && isnan(x2_Im_ref)))
            return CODE_FOUR;
    }
    return PASS;
}

