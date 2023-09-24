#include "Text.h"
#include "RectangleWithSizeArray.h"

#define ERR_RET(code)           \
        if(code) return code    \

int input_array_rectangle_with_size(RectangleWithSizeArray * array)
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

    array->data = (int*)calloc(2, sizeof(int));

    if (array->data == nullptr)
        return ALLOC_ERROR;

    error = input_size_rectangle_with_size(fp, array);

    ERR_RET(error);
    // if (error)
    //     return error;

    array->data = (int*)realloc(array->data, (2 + (array->data)[0] * (array->data)[1]) * sizeof(int));
    fill_zero(array);

    if (array->data == nullptr)
        return ALLOC_ERROR;

    error = input_data_rectangle_with_size(fp, array);

    ERR_RET(error);
    // if (error)
    //     return error;
    
    fclose(fp);

    return NO_ERROR;
}

int input_size_rectangle_with_size(FILE * fp, RectangleWithSizeArray * array)
{
    assert(fp != nullptr);
    assert(array != nullptr);

    int entered_num = fscanf(fp, "%d %d", &array->data[0], &array->data[1]);

    int execc_symbol = is_clear_input(fp);

    if (execc_symbol)
        return INPUT_SIZE_ANOTHER_SYMBOL_ERROR;
    if ((entered_num < 2) || array->data[0] == 0 || array->data[1] == 0)
        return INPUT_SIZE_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

int input_data_rectangle_with_size(FILE * fp, RectangleWithSizeArray * array)
{
    assert(fp != nullptr);
    assert(array != nullptr);

    int error = NO_ERROR;

    for (int num_string = 0; num_string < array->data[1]; num_string++)
    {
        error = input_data_string_rectangle_with_size(fp, array, num_string);

    ERR_RET(error);
        // if (error)
        //     return error;
    }

    return NO_ERROR;
}

int input_data_string_rectangle_with_size(FILE * fp, RectangleWithSizeArray * array, int num_string)
{
    assert(fp != nullptr);
    assert(array != nullptr);
    assert(num_string < array->data[1]);

    int error = NO_ERROR;
    int num_digit_in_string = 0;

    char symbol = getc(fp);
    while (symbol != '\n' && num_digit_in_string < array->data[0])
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                array->data[2 + num_digit_in_string + num_string * array->data[0]] =  array->data[2 + num_digit_in_string + num_string * array->data[0]] * 10 + char_to_digit(symbol);
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

void print_array_rectangle_with_size(const RectangleWithSizeArray * array)
{
    assert(array != nullptr);

    for (int num_string = 0; num_string < array->data[1]; num_string++)
    {
        for (int num_digit_in_string = 0; num_digit_in_string < array->data[0]; num_digit_in_string++)
            printf("%d ", array->data[2 + num_digit_in_string + num_string * array->data[0]]);
        printf("\n");
    }
}

void delete_array_rectangle_with_size(RectangleWithSizeArray * array)
{
    free(array->data);
    array = nullptr;
}

void fill_zero(RectangleWithSizeArray * array)
{
    for (int i = 2; i < array->data[0] * array->data[1]; i++)
        array->data[i] = 0;
}

int getter_rectangle_with_size(const RectangleWithSizeArray * array, int num_string, int num_coloumn, int * error)
{
    if (array == nullptr)
        *error = ARRAY_NULL_ERROR;

    if (num_string >= array->data[1] || num_coloumn >= array->data[0])
        *error = LEAVE_ARRAY_ERROR;
    
    return array->data[2 + num_coloumn + num_string * array->data[0]];
}

int setter_rectangle_with_size(RectangleWithSizeArray * array, int num_string, int num_coloumn, int new_data, int * error)
{
    if (array == nullptr)
        *error = ARRAY_NULL_ERROR;

    if (num_string >= array->data[1] || num_coloumn >= array->data[0])
        *error = LEAVE_ARRAY_ERROR;
    
    int past_data = array->data[2 + num_coloumn + num_string * array->data[0]];

    array->data[2 + num_coloumn + num_string * array->data[0]] = new_data;

    return past_data;
}