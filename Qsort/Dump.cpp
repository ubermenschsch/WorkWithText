#include "Qsort.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void data_dump(Data * data, int left, int right, int mid)
{
    for (int i = 0; i < data->size; i++)
    {
        printf("%s%d ", KNRM, i);
    }
    printf("\n");
    for (int i = 0; i < data->size; i++)
    {
        if (i == mid)
        {
            printf("%s%d ", KRED, data->data[i]);
        }
        else if (i == right)
        {
            printf("%s%d ", KYEL, data->data[i]);
        }
        else if (i == left)
        {
            printf("%s%d ", KYEL, data->data[i]);
        }
        else if (i < left || i > right)
        {
            printf("%s%d ", KGRN, data->data[i]);
        }
        else
        {
            printf("%s%d ", KMAG, data->data[i]);
        }
    }
    printf("%s\n\n", KNRM);
}