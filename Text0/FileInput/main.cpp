#include "Text.h"

// #define DATA1
#define DATA2
// #define DATA3

int main()
{
    int error = NO_ERROR;

    #ifdef DATA1
        Data1 data1;

        error = input_array1(&data1);
        if (error)
        {
            print_error(error);
            delete_array1(&data1);
            return 1;
        }

        int number = getter1(&data1, 2, 1, &error);
        if (error)
            return 1;
        printf("%d\n", number);

        print_data1(&data1);

        delete_array1(&data1);

    #endif // DATA1

    #ifdef DATA2
        int * data2 = nullptr;
        
        error = input_array2(&data2);

        if (error)
        {
            print_error(error);
            delete_array2(data2);
            return 1;
        }

        int number = 5;
        number = setter2(data2, 3, 0, number, &error);

        if (error)
        {
            print_error(error);
            return 1;
        }

        

        print_data2(data2);

        delete_array2(data2);
    #endif // DATA2

    #ifdef DATA3
        Data3 data3;

        error = input_array3(&data3);
        if (error)
        {
            print_error(error);
            delete_array3(&data3);
            return 1;
        }

        int number = 5;
        number = setter3(&data3, 3, 0, number, &error);
        if (error)
        {
            print_error(error);
            return 1;
        }

        printf("%d\n", number);
        print_data3(&data3);
        
        delete_array3(&data3);
    #endif // DATA3
}

// from files, triangle array, func suggest, 
