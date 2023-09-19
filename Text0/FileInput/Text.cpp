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
        return CALLOC_ERROR;

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

    // printf("Input excel data:\n");

    for (int num_string = 0; num_string < data1->size_y; num_string++)
    {
        // printf("%d) ", num_string + 1);

        error = input_data_string1(fp, data1, num_string);

        if (error)
            return error;

        // if (error != 0)
        // {
        //     printf("Uncorrect data. Input this string again:\n");
        //     for (int num_digit_in_string = 0; num_digit_in_string < data1->size_x; num_digit_in_string++)
        //         data1->data[num_digit_in_string + num_string * data1->size_x] = 0;
        //     num_string--;
        // }
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

            num_digit_in_string++;
        }

        else if (!isspace(symbol))
        {
            // error = 1;
            // symbol = getc(fp);
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

// void input_size2(int * data2)
// {
//     assert(data2 != nullptr);

//     printf("Input size of excel in format x*y:\n");

//     int entered_num = scanf("%d %d", &data2[0], &data2[1]);

//     int execc_symbol = is_clear_input();

//     while ((entered_num < 2) || execc_symbol || data2[0] == 0 || data2[1] == 0)
//     {
//         printf("Uncorrect data were entered\nTry again:\n");

//         entered_num = scanf("%d %d", &data2[0], &data2[1]);

//         execc_symbol = is_clear_input();
//     }
// }

// void input_data2(int * data2)
// {
//     assert(data2 != nullptr);

//     int error = 0;

//     printf("Input excel data:\n");

//     for (int num_string = 0; num_string < data2[1]; num_string++)
//     {
//         printf("%d) ", num_string + 1);

//         error = input_data_string2(data2, num_string);

//         if (error != 0)
//         {
//             printf("Uncorrect data. Input this string again:\n");
//             for (int num_digit_in_string = 0; num_digit_in_string < data2[0]; num_digit_in_string++)
//                 data2[2 + num_digit_in_string + num_string * data2[0]] = 0;
//             num_string--;
//         }
//     }
// }

// int input_data_string2(int * data2, int num_string)
// {
//     int error = 0;
//     int num_digit_in_string = 0;

//     char symbol = getchar();
//     while (symbol != '\n' && num_digit_in_string < data2[0])
//     {
//         if (isdigit(symbol))
//         {
//             while (isdigit(symbol))
//             {
//                 data2[2 + num_digit_in_string + num_string * data2[0]] =  data2[2 + num_digit_in_string + num_string * data2[0]] * 10 + char_to_digit(symbol);
//                 symbol = getchar();
//             }

//             num_digit_in_string++;
//         }

//         else if (isgraph(symbol))
//         {
//             error = 1;
//             symbol = getchar();
//         }

//         else
//         {
//             symbol = getchar();
//         }
//     }

//     if (symbol != '\n')
//         error += is_clear_input();

//     return error;
// }

// void print_data2(int * data2)
// {
//     assert(data2 != nullptr);

//     for (int num_string = 0; num_string < data2[1]; num_string++)
//     {
//         for (int num_digit_in_string = 0; num_digit_in_string < data2[0]; num_digit_in_string++)
//             printf("%d ", data2[2 + num_digit_in_string + num_string * data2[0]]);
//         printf("\n");
//     }
// }

void delete_array(Data1 * data1)
{
    data1->size_x = 0;
    data1->size_y = 0;
    free(data1->data);
    data1 = nullptr;
}

void print_error(int error)
{
    assert(error);

    switch (error)
    {
    case OPEN_FILE_ERROR:
        printf("Fail of open file. Try another name.\n");
        break;
    case DATA_NULL_ERROR:
        printf("Send null pointer of data. Check initialization of data.\n");
        break;
    case INPUT_SIZE_ALOTOF_PARAMETRS_ERROR:
        printf("Send a lot of parametrs. Check size of array.\n");
        break;
    case INPUT_SIZE_ANOTHER_SYMBOL_ERROR:
        printf("Send uncorrect data. Delete non-digit symbols.\n");
        break;
    case INPUT_STRING_ALOTOF_PARAMETRS_ERROR:
        printf("Send a lot of parametrs. Check size of array.\n");
        break;
    case INPUT_STRING_ANOTHER_SYMBOL_ERROR:
        printf("Send uncorrect data. Delete non-digit symbols.\n");
        break;
    case CALLOC_ERROR:
        printf("Fail of calloc. Check parameters of calloc function.\n");
        break;
    }
}

void fill_zero(int * data2)
{
    for (int i = 2; i < data2[0] * data2[1]; i++)
        data2[i] = 0;
}

int char_to_digit(char symbol)
{
    return symbol - '0';
}

int is_clear_input(FILE * fp)
{
    int execc_symbol = 0;

    char symbol = getc(fp);
    while (symbol != '\n')
    {
        if (!isspace(symbol))
            execc_symbol = 1;
        symbol = getc(fp);
    }
    
    return execc_symbol;
}
