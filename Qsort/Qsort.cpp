#include "Qsort.h"

static int partition(Data * data, int left, int right);
static int swap(Data * data, int left, int right, int mid);
static void last_swap(Data * data, int left, int right);

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
    assert(data != nullptr);
    assert(data->data != nullptr);
    assert(data->size > 0);

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

static int partition(Data * data, int left, int right)
{
    assert(data != nullptr);
    assert(data->data != nullptr);
    assert(data->size > 0);
    
    int mid = (left + right) / 2;
    int mid_value = data->data[mid];

    while (left < right)
    {
        // data_dump(data, left, right, mid);
        if (data->data[left] < mid_value)
        {
            left++;
        }
        else if (data->data[right] > mid_value)
        {
            right--;
        }
        else if (data->data[left] != data->data[right])
        {
            // data_dump(data, left, right, mid);
            mid = swap(data, left, right, mid);
            // data_dump(data, left, right, mid);
        }
        else
        {
            if (left == mid)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

    }

    return mid;
}

static int swap(Data * data, int left, int right, int mid)
{
    assert(data != nullptr);
    assert(data->data != nullptr);
    assert(data->size > 0);
    
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

static void last_swap(Data * data, int left, int right)
{
    assert(data != nullptr);
    assert(data->data != nullptr);
    assert(data->size > 0);
    assert(right - left == 1);

    if (data->data[left] <= data->data[right])
    {
        swap(data, left, right, 0);
    }
}
