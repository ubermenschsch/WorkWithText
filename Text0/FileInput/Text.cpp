#include "Text.h"

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
    case ALLOC_ERROR:
        printf("Fail of alloc. Check parameters of calloc function.\n");
        break;
    case LEAVE_ARRAY_ERROR:
        printf("You are leaving from array. Input another string and coloumn.\n");
        break;
    }
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
