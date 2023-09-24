#include "Text.h"
#include "TriangleArray.h"

static int input_size_triangle(FILE * fp, TriangleArray * array);
static int input_data_triangle(FILE * fp, TriangleArray * array);
static int input_data_string_triangle(FILE * fp, TriangleArray * array, int num_string);
static int num_elements_triangle(int num_string);

#define ERR_RET(code)           \
        if(code) return code    \

int input_array_triangle(TriangleArray * array)
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

    error = input_size_triangle(fp, array);

    ERR_RET(error);

    array->data = (int*)calloc(num_elements_triangle(array->num_string), sizeof(int));

    if (array->data == nullptr)
        return ALLOC_ERROR;

    error = input_data_triangle(fp, array);
    
    ERR_RET(error);
    
    fclose(fp);

    return NO_ERROR;
}

static int input_size_triangle(FILE * fp, TriangleArray * array)
{
    assert(fp != nullptr);
    assert(array != nullptr);

    int entered_num = fscanf(fp, "%d", &array->num_string);

    int execc_symbol = is_clear_input(fp);

    if (execc_symbol)
        return INPUT_SIZE_ANOTHER_SYMBOL_ERROR;
    if ((entered_num < 1) || array->num_string == 0)
        return INPUT_SIZE_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

static int input_data_triangle(FILE * fp, TriangleArray * array)
{
    assert(fp != nullptr);
    assert(array != nullptr);

    int error = NO_ERROR;

    for (int num_string = 0; num_string < array->num_string; num_string++)
    {
        error = input_data_string_triangle(fp, array, num_string);

        ERR_RET(error);
    }

    return NO_ERROR;
}

static int input_data_string_triangle(FILE * fp, TriangleArray * array, int num_string)
{
    assert(fp != nullptr);
    assert(array != nullptr);
    assert(num_string < array->num_string);

    int error = NO_ERROR;
    int num_elements = num_elements_triangle(num_string);

    int entered_num = 0;
    for (int num_digit_in_string = 0; num_digit_in_string <= num_string; num_digit_in_string++)
    {
        entered_num = fscanf(fp, "%d", &array->data[num_digit_in_string + num_elements]);
        if (entered_num != 1)
            return INPUT_STRING_ANOTHER_SYMBOL_ERROR;
    }

    if (is_clear_input(fp))
        return INPUT_STRING_ALOTOF_PARAMETRS_ERROR;

    return NO_ERROR;
}

void print_array_triangle(const TriangleArray * array)
{
    assert(array != nullptr);

    int num_elements_in_past_strings = 0;

    for (int num_string = 0; num_string < array->num_string; num_string++)
    {
        num_elements_in_past_strings = num_elements_triangle(num_string);
        for (int num_digit_in_string = 0; num_digit_in_string < (num_string + 1); num_digit_in_string++)
            printf("%d ", array->data[num_digit_in_string + num_elements_in_past_strings]);
        printf("\n");
    }
}

void delete_array_triangle(TriangleArray * array)
{
    array->num_string = 0;
    free(array->data);
    array = nullptr;
}

int getter_triangle(const TriangleArray * array, int num_string, int num_coloumn, int * error)
{
    assert(array != nullptr);

    if (array->data == nullptr)
        *error = ARRAY_NULL_ERROR;

    if (num_string >= array->num_string || num_coloumn >= array->num_string)
        *error = LEAVE_ARRAY_ERROR;
    
    return array->data[num_coloumn + num_elements_triangle(num_string)];
}

int setter_triangle(TriangleArray * array, int num_string, int num_coloumn, int new_data, int * error)
{
    assert(array != nullptr);

    if (array->data == nullptr)
        *error = ARRAY_NULL_ERROR;

    if (num_string >= array->num_string || num_coloumn >= array->num_string)
        *error = LEAVE_ARRAY_ERROR;
    
    int past_data = array->data[num_coloumn + num_elements_triangle(num_string)];

    array->data[num_coloumn + num_elements_triangle(num_string)] = new_data;

    return past_data;
}

static int num_elements_triangle(int num_string)
{
    int num_elements = 0;
    if (num_string > 0)
        for (int i = 1; i <= num_string; i++)
            num_elements += i;
    return num_elements;
}
