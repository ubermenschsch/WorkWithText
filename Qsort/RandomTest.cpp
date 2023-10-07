#include "RandomTest.h"

int set_data(Data * data)
{
    assert(data != nullptr);

    int error = NO_ERROR;

    printf("Input numbers of digit to test: ");
    error = scanf("%d", &data->size);

    if (error == 0 || data->size <= 0)
        return INPUT_SIZE_ERROR;

    data->data = (elem_t*)calloc(data->size, sizeof(elem_t));

    if (data->data == nullptr)
        return ALLOC_ERROR;

    for (int i = 0; i < data->size; i++)
    {
        srand(i);
        data->data[i] = rand();
    }

    return NO_ERROR;
}

int check_correct(Data * data)
{
    assert(data != nullptr);
    assert(data->data != nullptr);
    assert(data->size > 0);

    int couter = 0;

    for (int i = 0; i < data->size - 1; i++)
    {
        if (data->data[i] > data->data[i+1])
        {
            couter++;
        }
    }

    return couter;
}

void print_error(int error)
{
    assert(error);

    switch (error)
    {
    case INPUT_SIZE_ERROR:
        printf("Uncorrect numbers of digit. Print number >0 with only digit symbol.\n");
        break;
    case ALLOC_ERROR:
        printf("Fail of allocated memory.\n");
        break;
    }
}

int print_result(int result)
{
    if (result == 0)
    {
        printf("Qsort works correctly.\n");
        return 0;
    }
    else
    {
        printf("Qsort don't work correctly.\n");
        return 1;
    }
}