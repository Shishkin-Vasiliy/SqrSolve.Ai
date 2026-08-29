#include "header.h"


/**
    \brief Функция управления тестированием.
    Сначала функция читает тесты из файлов с помощью ReadTests(), затем получает код ошибки (или PASS при успешном прохождении)
    и затем выводит сообщение об ошибке в зависимоти от кода ошибки. В конце сообщает о количестве пройденных тестов.
*/
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


/**
    \brief Функция для определения кода ошибки.
    Функция получает тест и его номер, ищет эталонный тест с тем же номером в массиве эталонов RefTests[], 
    затем решает уравнение и сравнивает его с эталоном.
    \return Код Ошибки
*/
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

/**
    \brief Функция добавления прочитанного теста в массив тестов.
*/
void AddTest(int nEquations, struct equation Tests[], struct equation *Test)
{
    assert(Tests);
    assert(Test);

    if (nEquations < MAX_TESTS - 1)
        Tests[nEquations] = *Test;  
}

const char *TestsFile = "Tests.txt";
const char *RefTestsFile = "RefTests.txt";

/**
    \brief Функция чтения теста из файла.
    Получает строку с 9 числами и записывает их в структуру *Test по указателю
*/
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

/**
    \brief Функция чтения тестов.
    Запускает в цикле функцию GetTest() для чтения очередной строки в текстовом файле, полученные тесты записываются в массив тестов
*/
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

/**
    \brief Выводит сообщение об ошибке в тесте в зависимости от кода ошибки.
*/
void FailMessage(int FailCode, struct equation *Test, struct equation RefTests[], int NumTest)
{
    assert(Test);
    assert(RefTests);

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