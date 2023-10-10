#include "Qsort.h"

static size_t partition(void * first, size_t number, size_t size, int (*comparator) (const void *, const void *));
static size_t swap(void * first, size_t left, size_t right, size_t mid, size_t size);

static void * void_pointer(void * first, size_t shift, size_t size_elem);

static char * skip_nonalpha(char * string);
static int reverse_strncmp_alpha(const char * a, const char * b, size_t n);
static size_t skip_nonalpha_reverse(const char * string, size_t index_end);

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

    string_a = skip_nonalpha(string_a);
    string_b = skip_nonalpha(string_b);

    return strncmp(string_a, string_b, 200);
}

static char * skip_nonalpha(char * string)
{
    while (isalpha(*string) == 0 && *string != '\0')
    {
        string += 1;
    }

    return string;
}

int comparator_rhyme(const void * a, const void * b)
{
    assert(a != nullptr);
    assert(b != nullptr);

    char * string_a = *((char**)a);
    char * string_b = *((char**)b);

    return reverse_strncmp_alpha(string_a, string_b, 200);
}

static int reverse_strncmp_alpha(const char * a, const char * b, size_t n)
{
    size_t index_a = strlen(a) - 1;
    size_t index_b = strlen(b) - 1;

    if (a[index_a] == '\0' && b[index_b] == '\0')
    {
        return 0;
    }
    else if(a[index_a] == '\0')
    {
        return -1;
    }
    else if (b[index_b] == '\0')
    {
        return 1;
    }

    index_a = skip_nonalpha_reverse(a, index_a);
    index_b = skip_nonalpha_reverse(b, index_b);

    size_t couter = 0;
    while (a[index_a] == b[index_b] && index_a > 0 && index_b > 0 && couter < n)
    {
        index_a--;
        index_b--;

        couter++;
    }

    if (index_a > 0 && index_b > 0 && couter < n)
    {
        if (a[index_a] > b[index_b])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (couter >= n)
    {
        return 0;
    }
    else if (index_a == 0 && index_b == 0)
    {
        if (a[index_a] == b[index_b])
        {
            return 0;
        }
        else if (a[index_a] > b[index_b])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (index_a == 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

static size_t skip_nonalpha_reverse(const char * string, size_t index_end)
{
    while (isalpha(string[index_end]) == 0 && index_end > 0)
    {
        index_end--;
    }

    return index_end;
}
