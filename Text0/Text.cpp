#include "Text.h"

void input_size1(Data1 * data1)
{
    assert(data1 != nullptr);

    printf("Input size of excel in format x*y:\n");

    int entered_num = scanf("%lu %lu", &data1->size_x, &data1->size_y);

    int execc_symbol = is_clear_input();

    while ((entered_num < 2) || execc_symbol || data1->size_x == 0 || data1->size_y == 0)
    {
        printf("Uncorrect data were entered\nTry again:\n");

        entered_num = scanf("%lu %lu", &data1->size_x, &data1->size_y);

        execc_symbol = is_clear_input();
    }
}

void input_data1(Data1 * data1)
{
    assert(data1 != nullptr);

    int error = 0;

    printf("Input excel data:\n");

    for (int num_string = 0; num_string < data1->size_y; num_string++)
    {
        printf("%d) ", num_string + 1);

        error = input_data_string1(data1, num_string);

        if (error != 0)
        {
            printf("Uncorrect data. Input this string again:\n");
            for (int num_digit_in_string = 0; num_digit_in_string < data1->size_x; num_digit_in_string++)
                data1->data[num_digit_in_string + num_string * data1->size_x] = 0;
            num_string--;
        }
    }
}

int input_data_string1(Data1 * data1, int num_string)
{
    int error = 0;
    int num_digit_in_string = 0;

    char symbol = getchar();
    while (symbol != '\n' && num_digit_in_string < data1->size_x)
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                data1->data[num_digit_in_string + num_string * data1->size_x] =  data1->data[num_digit_in_string + num_string * data1->size_x] * 10 + char_to_digit(symbol);
                symbol = getchar();
            }

            num_digit_in_string++;
        }

        else if (isgraph(symbol))
        {
            error = 1;
            symbol = getchar();
        }

        else
        {
            symbol = getchar();
        }
    }

    if (symbol != '\n')
        error += is_clear_input();

    return error;
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

void input_size2(int * data2)
{
    assert(data2 != nullptr);

    printf("Input size of excel in format x*y:\n");

    int entered_num = scanf("%d %d", &data2[0], &data2[1]);

    int execc_symbol = is_clear_input();

    while ((entered_num < 2) || execc_symbol || data2[0] == 0 || data2[1] == 0)
    {
        printf("Uncorrect data were entered\nTry again:\n");

        entered_num = scanf("%d %d", &data2[0], &data2[1]);

        execc_symbol = is_clear_input();
    }
}

void input_data2(int * data2)
{
    assert(data2 != nullptr);

    int error = 0;

    printf("Input excel data:\n");

    for (int num_string = 0; num_string < data2[1]; num_string++)
    {
        printf("%d) ", num_string + 1);

        error = input_data_string2(data2, num_string);

        if (error != 0)
        {
            printf("Uncorrect data. Input this string again:\n");
            for (int num_digit_in_string = 0; num_digit_in_string < data2[0]; num_digit_in_string++)
                data2[2 + num_digit_in_string + num_string * data2[0]] = 0;
            num_string--;
        }
    }
}

int input_data_string2(int * data2, int num_string)
{
    int error = 0;
    int num_digit_in_string = 0;

    char symbol = getchar();
    while (symbol != '\n' && num_digit_in_string < data2[0])
    {
        if (isdigit(symbol))
        {
            while (isdigit(symbol))
            {
                data2[2 + num_digit_in_string + num_string * data2[0]] =  data2[2 + num_digit_in_string + num_string * data2[0]] * 10 + char_to_digit(symbol);
                symbol = getchar();
            }

            num_digit_in_string++;
        }

        else if (isgraph(symbol))
        {
            error = 1;
            symbol = getchar();
        }

        else
        {
            symbol = getchar();
        }
    }

    if (symbol != '\n')
        error += is_clear_input();

    return error;
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

int char_to_digit(char symbol)
{
    return symbol - '0';
}

int is_clear_input(void)
{
    int execc_symbol = 0;

    char symbol = getchar();
    while (symbol != '\n')
    {
        if (isgraph(symbol))
            execc_symbol = 1;
        symbol = getchar();
    }
    
    return execc_symbol;
}
