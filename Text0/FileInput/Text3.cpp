#include "Text.h"

int input_array3(Data3 * data3)
{
    int error = NO_ERROR;

    if (data3 == nullptr)
        return DATA_NULL_ERROR;
    
    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    printf("Input name of file:\n");
    scanf("%s", file_name);

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    error = input_size3(fp, data3);

    if (error)
        return error;

    data3->data = (int*)calloc(num_triangle_elements(data3->num_string), sizeof(int));

    if (data3->data == nullptr)
        return ALLOC_ERROR;

    error = input_data3(fp, data3);
    
    if (error)
        return error;
    
    fclose(fp);

    return NO_ERROR;
}

int input_size3(FILE * fp, Data3 * data3)
{
    assert(fp != nullptr);
    assert(data3 != nullptr);

    int entered_num = fscanf(fp, "%d", &data3->num_string);

    int execc_symbol = is_clear_input(fp);

    if (execc_symbol)
        return INPUT_SIZE_ANOTHER_SYMBOL_ERROR;
    if ((entered_num < 1) || data3->num_string == 0)
        return INPUT_SIZE_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

int input_data3(FILE * fp, Data3 * data3)
{
    assert(fp != nullptr);
    assert(data3 != nullptr);

    int error = NO_ERROR;

    for (int num_string = 0; num_string < data3->num_string; num_string++)
    {
        error = input_data_string3(fp, data3, num_string);

        if (error)
            return error;
    }

    return NO_ERROR;
}

int input_data_string3(FILE * fp, Data3 * data3, int num_string)
{
    assert(fp != nullptr);
    assert(data3 != nullptr);
    assert(num_string < data3->num_string);

    int error = NO_ERROR;
    int num_digit_in_string = 0;
    int num_elements = num_triangle_elements(num_string);

    char symbol = getc(fp);
    while (symbol != '\n' && num_digit_in_string <= num_string)
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                data3->data[num_elements] =  data3->data[num_elements] * 10 + char_to_digit(symbol);
                symbol = getc(fp);
            }

            if (!isspace(symbol))
                return INPUT_STRING_ANOTHER_SYMBOL_ERROR;

            num_elements++;
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

void print_data3(Data3 * data3)
{
    assert(data3 != nullptr);

    int num_elements_in_past_strings = 0;

    for (int num_string = 0; num_string < data3->num_string; num_string++)
    {
        num_elements_in_past_strings = num_triangle_elements(num_string);
        for (int num_digit_in_string = 0; num_digit_in_string < (num_string + 1); num_digit_in_string++)
            printf("%d ", data3->data[num_digit_in_string + num_elements_in_past_strings]);
        printf("\n");
    }
}

void delete_array3(Data3 * data3)
{
    data3->num_string = 0;
    free(data3->data);
    data3 = nullptr;
}

int num_triangle_elements(int num_string)
{
    int num_elements = 0;
    if (num_string > 0)
        for (int i = 1; i <= num_string; i++)
            num_elements += i;
    return num_elements;
}