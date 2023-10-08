#include "Qsort.h"

static size_t partition(void * first, size_t number, size_t size, int (*comparator) (const void *, const void *));
static size_t swap(void * first, size_t left, size_t right, size_t mid, size_t size);

static void * void_pointer(void * first, size_t shift, size_t size_elem);

void sort(void * first, size_t number, size_t size, int (*comparator) (const void *, const void *))
{
    assert(first != nullptr);
    assert(number > 0);
    assert(size > 0);

    size_t mid = partition(first, number, size, comparator);

    if ((mid + 1) > 1)
    {
        sort(first, mid + 1, size, comparator);
    }
    if ((number - (mid + 1)) > 1)
    {
        sort(void_pointer(first, mid + 1, size), number - (mid + 1), size, comparator);
    }
}

static size_t partition(void * first, size_t number, size_t size, int (*comparator) (const void *, const void *))
{
    assert(first != nullptr);
    assert(number > 0);
    assert(size > 0);

    size_t left  = 0;
    size_t right = number - 1;
    
    size_t mid = (left + right) / 2;

    while (left < right)
    {       
        // printf("Left:  %s\n", *(char**)void_pointer(first, left,  size));
        // printf("Mid:   %s\n", *(char**)void_pointer(first, mid,   size));
        // printf("Right: %s\n", *(char**)void_pointer(first, right, size));
        // printf("LM(<): %d\n", comparator(void_pointer(first, left,  size), void_pointer(first, mid,   size)));
        // printf("RM(>): %d\n", comparator(void_pointer(first, right, size), void_pointer(first, mid,   size)));
        // printf("LR:    %d\n", comparator(void_pointer(first, left,  size), void_pointer(first, right, size)));

        if      (comparator(void_pointer(first, left,  size), void_pointer(first, mid,   size)) <  0)
        {
            left++;
        }
        else if (comparator(void_pointer(first, right, size), void_pointer(first, mid,   size)) >  0)
        {
            right--;
        }
        else if (comparator(void_pointer(first, left,  size), void_pointer(first, right, size)) != 0)
        {
            printf("Swap\n");
            mid = swap(first, left, right, mid, size);
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

        printf("\n");

    }

    return mid;
}

static size_t swap(void * first, size_t left, size_t right, size_t mid, size_t size)
{
    assert(first != nullptr);
    assert(size > 0);
    assert(right > left);

    void * swap_data = calloc(1, size);

    memmove(swap_data,                       void_pointer(first, left, size),  size);
    memmove(void_pointer(first, left, size), void_pointer(first, right, size), size);
    memmove(void_pointer(first, right, size), swap_data,                       size);
    
    if      (mid == left)
    {
        mid = right;
    }
    else if (mid == right)
    {
        mid = left;
    }

    return mid;
}

static void * void_pointer(void * first, size_t shift, size_t size_elem)
{
    return (void*)((char*)first + shift * size_elem);
}

int comparator_int(const void * a, const void * b)
{
    assert(a != nullptr);
    assert(b != nullptr);
    
    return *((int*)a) - *((int*)b);
}

int comparator_string(const void * a, const void * b)
{
    assert(a != nullptr);
    assert(b != nullptr);

    char * string_a = *((char**)a);
    char * string_b = *((char**)b);

    while (isalpha(*string_a) == 0 && *string_a != '\0')
    {
        string_a += 1;
    }
    while (isalpha(*string_b) == 0 && *string_b != '\0')
    {
        string_b += 1;
    }

    return strncmp(string_a, string_b, 200);
}
