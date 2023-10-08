#ifndef QSORT_H
#define QSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void sort(void * first, size_t number, size_t size, int (*comparator) (const void *, const void *));

int comparator_int(const void * a, const void * b);
int comparator_string(const void * a, const void * b);

#endif // QSORT_H