#include "header.h"

void FileClearBuf(FILE *file)
{
    assert(file);
    
    int ch = 0;
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
        ;
}