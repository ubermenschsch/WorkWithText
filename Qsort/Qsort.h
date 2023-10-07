#ifndef QSORT_H
#define QSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int elem_t;

struct Data
{
    elem_t * data;
    int size;
};

void ctor_data(Data * data);
void dtor_data(Data * data);

void sort(Data * data, int left, int right);
void data_dump(Data * data, int left, int right, int mid);


#endif // QSORT_H