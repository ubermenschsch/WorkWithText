#include "Text.h"

int main()
{

    Data1 data1;

    input_size1(&data1);

    data1.data = (int*)calloc(data1.size_x * data1.size_y, sizeof(int));

    input_data1(&data1);

    print_data1(&data1);

    free(data1.data);
    
    int * data2 = (int*)calloc(2, sizeof(int));

    input_size2(data2);

    data2 = (int*)realloc(data2, (2 + data2[0] * data2[1]) * sizeof(int));
    fill_zero(data2);

    input_data2(data2);

    print_data2(data2);

    free(data2);
}

// from files, triangle array, func suggest, 
