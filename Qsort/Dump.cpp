#include "Common.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void data_dump(int * first, size_t number, size_t left, size_t right, size_t mid)
{
    for (size_t i = 0; i < number; i++)
    {
        printf("%s%ld ", KNRM, i);
    }
    printf("\n");
    for (size_t i = 0; i < number; i++)
    {
        if (i == mid)
        {
            printf("%s%d ", KRED, ((int*)first)[i]);
        }
        else if (i == right)
        {
            printf("%s%d ", KYEL, ((int*)first)[i]);
        }
        else if (i == left)
        {
            printf("%s%d ", KYEL, ((int*)first)[i]);
        }
        else if (i < left || i > right)
        {
            printf("%s%d ", KGRN, ((int*)first)[i]);
        }
        else
        {
            printf("%s%d ", KMAG, ((int*)first)[i]);
        }
    }
    printf("%s\n\n", KNRM);
}