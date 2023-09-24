#ifndef TEXT_H
#define TEXT_H 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>


const size_t MAX_NAME_FILE_LENGHT = 255;

enum Error
{
    NO_ERROR                            = 0,
    OPEN_FILE_ERROR                     = 1,
    ARRAY_NULL_ERROR                    = 2,
    INPUT_SIZE_ALOTOF_PARAMETRS_ERROR   = 3,
    INPUT_SIZE_ANOTHER_SYMBOL_ERROR     = 4,
    INPUT_STRING_ALOTOF_PARAMETRS_ERROR = 5,
    INPUT_STRING_ANOTHER_SYMBOL_ERROR   = 6,
    ALLOC_ERROR                         = 7,
    LEAVE_ARRAY_ERROR                   = 8,
};

void print_error(int error);

int char_to_digit(char symbol);
int is_clear_input(FILE * fp);

#endif // TEXT_H
