#include "header.h"

void CmdFlag(int *TestFlag, int *UserFlag, int argc, char *argv[])
{
    assert(TestFlag);

    int ch = 0;

    while (--argc > 0 && (ch = (*++argv)[0]) == '-')
    {
        while (ch = *++(argv[0]))
        {
            switch(ch)
            {
                case 't':
                    *TestFlag = 1;
                    break;
                
                case 'u':
                    *UserFlag = 1;
                    break;   
            }
        }
    }
}