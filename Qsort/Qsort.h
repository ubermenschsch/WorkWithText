#ifndef QSORT_H
#define QSORT_H

#include <stdio.h>

void input_filename(char * file_name);
void input_data(char * file_name, int ** data, int *size);

void sort(int data[], int left, int right);
int partition(int data[], int left, int right);


#endif // QSORT_H