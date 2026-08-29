#include "header.h"

void PrintStory(int nEquations, struct equation story[], int flag)
{
    assert(story);

    printf("\n");
    SlowPrintf(PURPLE_CNSL "ИСТОРИЯ РЕШЕНИЙ:" NO_COLOR "\n\n");
    printf(GREEN_CNSL "---------------------------------------------------------------" NO_COLOR "\n");
        
    int i = nEquations; 
    int j = 0;

    if (flag)
    {
        for (j = i; j < STORY_SIZE;)
        {
            Output(&story[j]);
            j++;                     
        }
    
        for (j = 0; j < i;)
        {
            Output(&story[j]);
            j++;                       
        }   
    }

    else
        for (j = 0; j < STORY_SIZE&& j < i;)
        {
            Output(&story[j]);
            j++;
        }
    
    printf("\n");
    printf(GREEN_CNSL "---------------------------------------------------------------" NO_COLOR "\n");
}


/**
	\details Функция SetFlag используется для реализации вывода истории запросов в порядке очереди.
	Уравнения последовательно добавляются в массив вплоть до момента, пока они полностью не заполнят массив истории.
	Когда массив заполнился, функция SetFlag устанавливает вспомогательный флаг в 1 и сбрасывает количество уравнений в 0 
	- теперь массив как бы начинает заполнятся в обычном порядке начиная с 1 индекса до крайнего. При следующем достижении nEquations 
	значения STORY_SIZE - 1 флаг снова опускается (если в этот момент вызвать функцию вывода истории, то все уравнения выведутся по порядку, в котором они стоят в массиве).
	Если будет введено еще одно уравнение (nEquations == STORY_SIZE), то описанная процедура снова повторяется.
	Значение установленное во флаге влияет на поведение функции PrintStory: 
	Если flag == 1, то уравнения выводятся от индекса равного nEquations до конца массива (элементы после nEquations), 
	а затем элементы до nEquations. 
	Если flag == 0, то уравнения выводятся в обычном порядке от индекса равного 0 до конца массива.
*/
void SetFlag (int *nEquations, bool *flag)
{
	assert(nEquations);
	assert(flag);
	
    if (*nEquations == STORY_SIZE)
		{
			*nEquations = 0;
			*flag = 1;
		}
	else if (*nEquations == STORY_SIZE- 1)
		{
			*flag = 0;
		}
}


/**
    \details Функция AddEq копирует структуру уравнения в массив story для дальнейшего вывода истории запросов.
             Выводятся последние STORY_SIZE запросов.
             Ветка else в этой функции нужна для добавления элемента в конец массива, так как это нужно для реализации
             вывода истории в порядке очереди (более подробный алгоритм описан в описании функции SetFlag)
*/
void AddEq(int nEquations, struct equation story[], struct equation *Eq)
{
    assert(story);
    assert(Eq);

    if (nEquations < STORY_SIZE)
        story[nEquations] = *Eq;
    else
        story[0] = *Eq;    
}