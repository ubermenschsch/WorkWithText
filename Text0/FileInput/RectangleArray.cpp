#include "Text.h"
#include "RectangleArray.h"

int input_array_rectangle(RectangleArray * array)
{
    int error = NO_ERROR;

    if (array == nullptr)
        return ARRAY_NULL_ERROR;
    
    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    printf("Input name of file:\n");
    scanf("%s", file_name);

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    error = input_size_rectangle(fp, array);

    if (error)
        return error;

    array->data = (int*)calloc(array->size_x * array->size_y, sizeof(int));

    if (array->data == nullptr)
        return ALLOC_ERROR;

    error = input_data_rectangle(fp, array);
    
    if (error)
        return error;
    
    fclose(fp);

    return NO_ERROR;
}

int input_size_rectangle(FILE * fp, RectangleArray * array)
{
    assert(fp != nullptr);
    assert(array != nullptr);

    int entered_num = fscanf(fp, "%d %d", &array->size_x, &array->size_y);

    int execc_symbol = is_clear_input(fp);

    if (execc_symbol)
        return INPUT_SIZE_ANOTHER_SYMBOL_ERROR;
    if ((entered_num < 2) || array->size_x == 0 || array->size_y == 0)
        return INPUT_SIZE_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

int input_data_rectangle(FILE * fp, RectangleArray * array)
{
    assert(fp != nullptr);
    assert(array != nullptr);

    int error = NO_ERROR;

    for (int num_string = 0; num_string < array->size_y; num_string++)
    {
        error = input_data_string_rectangle(fp, array, num_string);

        if (error)
            return error;
    }

    return NO_ERROR;
}

int input_data_string_rectangle(FILE * fp, RectangleArray * array, int num_string)
{
    assert(fp != nullptr);
    assert(array != nullptr);
    assert(num_string < array->size_y);

    int error = NO_ERROR;
    int num_digit_in_string = 0;

    char symbol = getc(fp);
    while (symbol != '\n' && num_digit_in_string < array->size_x)
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                array->data[num_digit_in_string + num_string * array->size_x] =  array->data[num_digit_in_string + num_string * array->size_x] * 10 + char_to_digit(symbol);
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

void print_array_rectangle(const RectangleArray * array)
{
    assert(array != nullptr);

    for (int num_string = 0; num_string < array->size_y; num_string++)
    {
        for (int num_digit_in_string = 0; num_digit_in_string < array->size_x; num_digit_in_string++)
            printf("%d ", array->data[num_digit_in_string + num_string * array->size_x]);
            printf("\n");
    }
}

void delete_array_rectangle(RectangleArray * array)
{
    array->size_x = 0;
    array->size_y = 0;
    free(array->data);
    array = nullptr;
}

int getter_rectangle(const RectangleArray * array, int num_string, int num_coloumn, int * error)
{
    assert(array != nullptr);

    if (array->data == nullptr)
        *error = ARRAY_NULL_ERROR;

    if (num_string >= array->size_y || num_coloumn >= array->size_x)
        *error = LEAVE_ARRAY_ERROR;
    
    return array->data[num_coloumn + num_string * array->size_x];
}

int setter_rectangle(RectangleArray * array, int num_string, int num_coloumn, int new_data, int * error)
{
    assert(array != nullptr);

    if (array->data == nullptr)
        *error = ARRAY_NULL_ERROR;

    if (num_string >= array->size_y || num_coloumn >= array->size_x)
        *error = LEAVE_ARRAY_ERROR;
    
    int past_data = array->data[num_coloumn + num_string * array->size_x];

    array->data[num_coloumn + num_string * array->size_x] = new_data;

    return past_data;
}
