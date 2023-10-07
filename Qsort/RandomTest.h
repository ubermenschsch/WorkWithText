#ifndef RANDOMTEST_H
#define RANDOMTEST_H

#include "Qsort.h"

enum Error
{
    NO_ERROR         = 0,
    INPUT_SIZE_ERROR = 1,
    ALLOC_ERROR      = 2,
};

int set_data(Data * data);
int check_correct(Data * data);
void print_error(int error);
int print_result(int result);

#endif // RANDOMTEST_H