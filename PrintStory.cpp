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