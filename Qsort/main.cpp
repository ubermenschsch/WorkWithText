#include "InputData.h"
#include "Qsort.h"

int main()
{
    // char file_name[256] = {};
    // input_filename(file_name);

    Data data;
    ctor_data(&data);
    // input_data(file_name, &data);
    data.size = 100000000;
    data.data = (elem_t*)calloc(data.size, sizeof(elem_t));
    for (int i = 0; i < data.size; i++)
    {
        srand(i);
        data.data[i] = rand();
    }

    sort(&data, 0, data.size - 1);

    // data_dump(&data, 0, 0, 0);

    int couter = 0;
    for (int i = 0; i < data.size - 1; i++)
    {
        if (data.data[i] > data.data[i+1])
        {
            couter++;
        }
    }

    printf("%d\n", couter);

    dtor_data(&data);
}