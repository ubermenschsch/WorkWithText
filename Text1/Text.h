#include <stdio.h>
#include <assert.h>

const int MAX_LENGHT           = 46;
const int MAX_NUM_STRING       = 21;
const int MAX_NAME_FILE_LENGHT = 255;

enum Error
{
    NO_ERROR                            = 0,
    OPEN_FILE_ERROR                     = 1,
    TEXT_NULL_ERROR                     = 2,
    INPUT_STRING_ERROR                  = 3,
    // INPUT_MORE_LENGHT_ERROR             = 3,
    // INPUT_MORE_STRING_ERROR             = 4,
    // ALLOC_ERROR                         = 7,
    // LEAVE_ARRAY_ERROR                   = 8,
};

int input_text(char text[][MAX_LENGHT]);
void print_text(char text[][MAX_LENGHT]);
void print_error(int error);