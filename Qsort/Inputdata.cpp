#include "Qsort.h"

#include <stdlib.h>

void input_filename(char * file_name)
{
    printf("Input name of file:\n");
    scanf("%s", file_name);
}

void input_data(char * file_name, int ** data, int *size)
{
    FILE * fp = fopen(file_name, "r");

    fscanf(fp, "%d", size);

    *data = (int*)calloc(*size, sizeof(int));

    for (int i = 0; i < *size; i++)
    {
        fscanf(fp, "%d", (*data + i));
    }

    fclose(fp);
}