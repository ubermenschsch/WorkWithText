#include "Qsort.h"

void input_filename(char * file_name)
{
    printf("Input name of file:\n");
    scanf("%s", file_name);
}

void input_data(char * file_name, Data * data)
{
    FILE * fp = fopen(file_name, "r");

    fscanf(fp, "%d", &data->size);

    data->data = (elem_t*)calloc(data->size, sizeof(int));

    for (int i = 0; i < data->size; i++)
    {
        fscanf(fp, "%d", &data->data[i]);
    }

    fclose(fp);
}
