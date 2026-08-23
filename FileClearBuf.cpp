#include "header.h"

void FileClearBuf(FILE *file)
{
    int ch = 0;
    while ((ch = fgetc(file)) != '\n')
        ;
}