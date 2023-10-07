#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "Qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum Error
{
    NO_ERROR             = 0,
    INPUT_FILENAME_ERROR = 1,
    OPEN_FILE_ERROR      = 2,
    UNCORRECT_SIZE_ERROR = 3,
    ALLOC_ERROR          = 4,
    INPUT_DATA_ERROR     = 5
};

int input_filename(char * file_name);
int input_data(char * file_name, Data * data);

#endif // INPUTDATA_H