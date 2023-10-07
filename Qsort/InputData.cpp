#include "InputData.h"

int input_filename(char * file_name)
{
    printf("Input name of file:\n");
    int error = scanf("%s", file_name);
    if (error == 0)
        return INPUT_FILENAME_ERROR;

    return NO_ERROR;
}

int input_data(char * file_name, Data * data)
{
    assert(data != nullptr);
    assert(file_name != nullptr);

    int error = NO_ERROR;

    FILE * fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    error = fscanf(fp, "%d", &data->size);

    if (data->size <= 0 || error == 0 || error == EOF)
        return UNCORRECT_SIZE_ERROR;

    data->data = (elem_t*)calloc(data->size, sizeof(elem_t));

    if (data->data == nullptr)
        return ALLOC_ERROR;

    for (int i = 0; i < data->size; i++)
    {
        error = fscanf(fp, "%d", &data->data[i]);
        if (error == 0 || error == EOF)
            return INPUT_DATA_ERROR;
    }

    fclose(fp);

    return NO_ERROR;
}
