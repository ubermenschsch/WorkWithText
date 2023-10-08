#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int MAX_NAME_FILE_LENGHT = 255;

struct Text
{
    char *  buffer;
    long    size_buffer;
    char ** data;
    int     num_string;
};

enum Error
{
    NO_ERROR                   = 0,
    TEXT_NULL_ERROR            = 1,
    OPEN_FILE_ERROR            = 2,
    FILE_SIZE_ERROR            = 3,
    ALLOC_BUFF_ERROR           = 4,
    ALLOC_DATA_ERROR           = 5,
    INPUT_STRING_ERROR         = 6,
};

void ctor_text(Text * text);
void dtor_text(Text * text);

void input_filename(char * file_name);

int input_text(Text * text, char * filename);
// void print_text(Text * text);
int output_text(Text * text);
void print_error(int error);

#endif // TEXT_H