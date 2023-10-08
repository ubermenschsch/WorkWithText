#ifndef COOMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int elem_t;

struct Data
{
    elem_t * data;
    size_t size;
};

void ctor_data(Data * data);
void dtor_data(Data * data);


void data_dump(int * first, size_t number, size_t left, size_t right, size_t mid);

#endif // COMMON_H