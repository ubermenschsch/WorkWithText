#include "Qsort.h"

int main()
{
    char file_name[256] = {};
    input_filename(file_name);

    Data data;
    ctor_data(&data);
    input_data(file_name, &data);

    // data_dump(&data, 0, data.size - 1, 2);

    sort(&data, 0, data.size - 1);

    dtor_data(&data);
}