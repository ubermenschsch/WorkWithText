#include "Text.h"

int input_array2(int ** data2)
{
    int error = NO_ERROR;

    if (*data2 != nullptr)
        return DATA_NULL_ERROR;
    
    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    printf("Input name of file:\n");
    scanf("%s", file_name);

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    *data2 = (int*)calloc(2, sizeof(int));

    if (*data2 == nullptr)
        return ALLOC_ERROR;

    error = input_size2(fp, *data2);

    if (error)
        return error;

    *data2 = (int*)realloc(*data2, (2 + (*data2)[0] * (*data2)[1]) * sizeof(int));
    fill_zero(*data2);

    if (*data2 == nullptr)
        return ALLOC_ERROR;

    error = input_data2(fp, *data2);

    if (error)
        return error;
    
    fclose(fp);

    return NO_ERROR;
}

int input_size2(FILE * fp, int * data2)
{
    assert(fp != nullptr);
    assert(data2 != nullptr);

    int entered_num = fscanf(fp, "%d %d", &data2[0], &data2[1]);

    int execc_symbol = is_clear_input(fp);

    if (execc_symbol)
        return INPUT_SIZE_ANOTHER_SYMBOL_ERROR;
    if ((entered_num < 2) || data2[0] == 0 || data2[1] == 0)
        return INPUT_SIZE_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

int input_data2(FILE * fp, int * data2)
{
    assert(fp != nullptr);
    assert(data2 != nullptr);

    int error = NO_ERROR;

    for (int num_string = 0; num_string < data2[1]; num_string++)
    {
        error = input_data_string2(fp, data2, num_string);

        if (error)
            return error;
    }

    return NO_ERROR;
}

int input_data_string2(FILE * fp, int * data2, int num_string)
{
    assert(fp != nullptr);
    assert(data2 != nullptr);
    assert(num_string < data2[1]);

    int error = NO_ERROR;
    int num_digit_in_string = 0;

    char symbol = getc(fp);
    while (symbol != '\n' && num_digit_in_string < data2[0])
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                data2[2 + num_digit_in_string + num_string * data2[0]] =  data2[2 + num_digit_in_string + num_string * data2[0]] * 10 + char_to_digit(symbol);
                symbol = getc(fp);
            }

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

void print_data2(int * data2)
{
    assert(data2 != nullptr);

    for (int num_string = 0; num_string < data2[1]; num_string++)
    {
        for (int num_digit_in_string = 0; num_digit_in_string < data2[0]; num_digit_in_string++)
            printf("%d ", data2[2 + num_digit_in_string + num_string * data2[0]]);
        printf("\n");
    }
}

void delete_array2(int * data2)
{
    free(data2);
    data2 = nullptr;
}

void fill_zero(int * data2)
{
    for (int i = 2; i < data2[0] * data2[1]; i++)
        data2[i] = 0;
}
