#include "header.h"

void PrintStory(int nEquations, struct equation story[], int flag)
{
    assert(story);

    printf("\n");
    printf(PURPLE "ИСТОРИЯ РЕШЕНИЙ:" NO_COLOR "\n\n");
    printf(GREEN "---------------------------------------------------------------" NO_COLOR "\n");
        
    int i = nEquations; 
    int j = 0;

    if (flag)
    {
        for (j = i; j < BUF_SIZE;)
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
        for (j = 0; j < BUF_SIZE && j < i;)
        {
            Output(&story[j]);
            j++;
        }
    
    printf("\n");
    printf(GREEN "---------------------------------------------------------------" NO_COLOR "\n");
}