#include "header.h"

// эта функция устанавливает значение флага который 
// используется для реализации печати истории введенных уравнений на очереди 

int SetFlag(int nEquations)
{
    int flag = 0;

    if (nEquations == BUF_SIZE)
		{
			nEquations = 0;
			flag = 1;
		}
	else if (nEquations == BUF_SIZE - 1)
		{
			flag = 0;
		}

    return flag;
}