#ifndef QSORT_H
#define QSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

struct Data
{
    elem_t * data;
    int size;
};

void ctor_data(Data * data);
void dtor_data(Data * data);

void input_filename(char * file_name);
void input_data(char * file_name, Data * data);

void sort(Data * data, int left, int right);
int partition(Data * data, int left, int right);
int swap(Data * data, int left, int right, int mid);
void data_dump(Data * data, int left, int right, int mid);
void last_swap(Data * data, int left, int right);


#endif // QSORT_H