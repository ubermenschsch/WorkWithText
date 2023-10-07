#include "Qsort.h"

int main()
{
    char file_name[256] = {};
    input_filename(file_name);

    int size = 0;
    int * data = nullptr;
    input_data(file_name, &data, &size);

    sort(data, 0, size - 1);
}