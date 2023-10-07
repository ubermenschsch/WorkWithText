#include "Qsort.h"

void sort(int data[], int left, int right)
{
    int mid = partition(data, left, right);
    printf("%d : data[%d] = %d\n", mid, mid, data[mid]);
    if (mid - left > 0)
    {
        sort(data, left, mid);
    }
    if (right - (mid + 1) > 0)
    {
        sort(data, mid + 1, right);
    }
}

int partition(int data[], int left, int right)
{
    return (left + right) / 2;
}