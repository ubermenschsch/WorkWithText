#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int MAX_LENGHT           = 46;
const int MAX_NAME_FILE_LENGHT = 255;

struct Text
{
    char * buffer = nullptr;
    char ** data = nullptr;
    int num_string = 0;
    int lenght = MAX_LENGHT;
};

enum Error
{
    NO_ERROR                            = 0,
    TEXT_NULL_ERROR                     = 1,
    OPEN_FILE_ERROR                     = 2,
    FILE_NUM_STRING_ERROR               = 3,
    ALLOC_BUFF_ERROR                    = 4,
    ALLOC_DATA_ERROR                    = 5,
    INPUT_STRING_ERROR                  = 6,
};

int input_text(Text * text);
void print_text(Text * text);
void print_error(int error);
void delete_text(Text * text);

#endif // TEXT_H