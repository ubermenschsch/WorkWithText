#include "Text.h"

int input_array1(Data1 * data1)
{
    int error = NO_ERROR;

    if (data1 == nullptr)
        return DATA_NULL_ERROR;
    
    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    printf("Input name of file:\n");
    scanf("%s", file_name);

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    error = input_size1(fp, data1);

    if (error)
        return error;

    data1->data = (int*)calloc(data1->size_x * data1->size_y, sizeof(int));

    if (data1->data == nullptr)
        return ALLOC_ERROR;

    error = input_data1(fp, data1);
    
    if (error)
        return error;
    
    fclose(fp);

    return NO_ERROR;
}

int input_size1(FILE * fp, Data1 * data1)
{
    assert(fp != nullptr);
    assert(data1 != nullptr);

    int entered_num = fscanf(fp, "%lu %lu", &data1->size_x, &data1->size_y);

    int execc_symbol = is_clear_input(fp);

    if (execc_symbol)
        return INPUT_SIZE_ANOTHER_SYMBOL_ERROR;
    if ((entered_num < 2) || data1->size_x == 0 || data1->size_y == 0)
        return INPUT_SIZE_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

int input_data1(FILE * fp, Data1 * data1)
{
    assert(fp != nullptr);
    assert(data1 != nullptr);

    int error = NO_ERROR;

    for (int num_string = 0; num_string < data1->size_y; num_string++)
    {
        error = input_data_string1(fp, data1, num_string);

        if (error)
            return error;
    }

    return NO_ERROR;
}

int input_data_string1(FILE * fp, Data1 * data1, int num_string)
{
    assert(fp != nullptr);
    assert(data1 != nullptr);
    assert(num_string < data1->size_y);

    int error = NO_ERROR;
    int num_digit_in_string = 0;

    char symbol = getc(fp);
    while (symbol != '\n' && num_digit_in_string < data1->size_x)
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                data1->data[num_digit_in_string + num_string * data1->size_x] =  data1->data[num_digit_in_string + num_string * data1->size_x] * 10 + char_to_digit(symbol);
                symbol = getc(fp);
            }

            if (!isspace(symbol))
                return INPUT_STRING_ANOTHER_SYMBOL_ERROR;

            num_digit_in_string++;
        }

        else if (!isspace(symbol))
        {
            return INPUT_STRING_ANOTHER_SYMBOL_ERROR;
        }

        else
        {
            symbol = getc(fp);
        }
    }

    if (symbol != '\n')
        if (is_clear_input(fp))
            return INPUT_STRING_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

void print_data1(Data1 * data1)
{
    assert(data1 != nullptr);

    for (int num_string = 0; num_string < data1->size_y; num_string++)
    {
        for (int num_digit_in_string = 0; num_digit_in_string < data1->size_x; num_digit_in_string++)
            printf("%d ", data1->data[num_digit_in_string + num_string * data1->size_x]);
        printf("\n");
    }
}

void delete_array1(Data1 * data1)
{
    data1->size_x = 0;
    data1->size_y = 0;
    free(data1->data);
    data1 = nullptr;
}

int getter1(const Data1 * data1, int num_string, int num_coloumn, int * error)
{
    assert(data1 != nullptr);

    if (data1->data == nullptr)
        *error = DATA_NULL_ERROR;

    if (num_string >= data1->size_y || num_coloumn >= data1->size_x)
        *error = LEAVE_ARRAY_ERROR;
    
    return data1->data[num_coloumn + num_string * data1->size_x];
}

int setter1(Data1 * data1, int num_string, int num_coloumn, int new_data, int * error)
{
    assert(data1 != nullptr);

    if (data1->data == nullptr)
        *error = DATA_NULL_ERROR;

    if (num_string >= data1->size_y || num_coloumn >= data1->size_x)
        *error = LEAVE_ARRAY_ERROR;
    
    int past_data = data1->data[num_coloumn + num_string * data1->size_x];

    data1->data[num_coloumn + num_string * data1->size_x] = new_data;

    return past_data;
}
