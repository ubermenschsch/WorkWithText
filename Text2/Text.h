#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int MAX_LENGHT           = 46;
const int MAX_NAME_FILE_LENGHT = 255;

enum Error
{
    NO_ERROR                            = 0,
    OPEN_FILE_ERROR                     = 1,
    FILE_SIZE_ERROR                     = 2,
    TEXT_NULL_ERROR                     = 3,
    INPUT_STRING_ERROR                  = 4,
    // INPUT_MORE_LENGHT_ERROR             = 3,
    // INPUT_MORE_STRING_ERROR             = 4,
    ALLOC_ERROR                         = 7,
    // LEAVE_ARRAY_ERROR                   = 8,
};

int input_text(char * text);
void print_text(char * text);
void print_error(int error);

#endif // TEXT_H