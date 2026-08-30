#include "header.h"

/**
    \brief Функция CmdFlag считывает аргументы командной строки и устанавливает нужные флаги для запуска.
    Подробнее о флагах в описании к ENUM FLAGS.
    \param[in] Flags
    \param[in] args
    \param[in] argv
*/
void CmdFlag(struct Flags *Flags, int argc, char *argv[])
{
    assert(Flags);

    int ch = 0;

    while (--argc > 0 && (ch = (*++argv)[0]) == '-')
    {
        while (ch = *++(argv[0]))
        {
            switch(ch)
            {
                case 't':
                    (*Flags).Test = 1;
                    break;
                
                case 'u':
                    (*Flags).User = 1;
                    break;
                
                case 'g':
                    (*Flags).Graph = 1;
                    break;
                    
                default:
                    return;    
            }
        }
    }
}