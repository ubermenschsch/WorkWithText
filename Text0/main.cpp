#include "Text.h"

int main()
{
    int error;

    Data1 data1;

    input_size(&data1);

    data1.data = (int*)calloc(data1.size_x * data1.size_y, sizeof(int));

    input_data(&data1);

    print_data(&data1);

    free(data1.data);
}
