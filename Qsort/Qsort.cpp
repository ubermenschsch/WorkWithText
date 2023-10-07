#include "Qsort.h"

void ctor_data(Data * data)
{
    data->data = nullptr;
    data->size = 0;
}

void dtor_data(Data * data)
{
    free(data->data);
    data->size = -1;
}

void sort(Data * data, int left, int right)
{
    if (right - left == 1)
    {
        last_swap(data, left, right);
    }
    else
    {
        int mid = partition(data, left, right);
        if (mid - left > 0)
        {
            sort(data, left, mid);
        }
        if (right - (mid + 1) > 0)
        {
            sort(data, mid + 1, right);
        }
    }
}

int partition(Data * data, int left, int right)
{
    int mid = (left + right) / 2;
    int mid_value = data->data[mid];
    // while (data[left] < mid_value)
    // {
    //     left++;
    // }
    // while (data[right] > mid_value)
    // {
    //     right--;
    // }
    // swap(data, left, right);
    // left++;
    // right--;

    while (left < right)
    {
        data_dump(data, left, right, mid);
        if (data->data[left] < mid_value)
        {
            left++;
        }
        else if (data->data[right] > mid_value)
        {
            right--;
        }
        else
        {
            data_dump(data, left, right, mid);
            mid = swap(data, left, right, mid);
            data_dump(data, left, right, mid);
            left++;
            right--;
        }

    }

    return mid;
}

int swap(Data * data, int left, int right, int mid)
{
    int swap_data = data->data[right];
    data->data[right] = data->data[left];
    data->data[left] = swap_data;

    if (mid == left)
    {
        mid = right;
    }
    else if (mid == right)
    {
        mid = left;
    }

    return mid;
}

// void data_dump(Data * data, int left, int right, int mid)
// {
//     for (int i = 0; i < data->size; i++)
//     {
//         printf("%0*d ", 2, i);
//     }
//     printf("\n");
//     for (int i = 0; i < data->size; i++)
//     {
//         if (i == left)
//         {
//             printf("<%d ", data->data[i]);
//         }
//         else if (i == right)
//         {
//             printf("%d> ", data->data[i]);
//         }
//         else if (i == mid)
//         {
//             printf("[%d] ", data->data[i]);
//         }
//         else
//         {
//             printf("%d ", data->data[i]);
//         }
//     }
//     printf("\n\n");
// }

void last_swap(Data * data, int left, int right)
{
    if (data->data[left] <= data->data[right])
    {
        swap(data, left, right, 0);
    }
}