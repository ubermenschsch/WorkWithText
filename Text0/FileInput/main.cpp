#include "Text.h"

// #define RECT_ARR
// #define RECT_SIZE_ARR
#define TRIANGLE_ARR

#ifdef RECT_ARR
    #include "RectangleArray.h"
#endif // RECT_ARR
#ifdef RECT_SIZE_ARR
    #include "RectangleWithSizeArray.h"
#endif // RECT_SIZE_ARR
#ifdef TRIANGLE_ARR
    #include "TriangleArray.h"
#endif // TRIANGLE_ARR

int main()
{
    int error = NO_ERROR;

    #ifdef RECT_ARR
        RectangleArray array;

        error = input_array_rectangle(&array);
        if (error)
        {
            print_error(error);
            delete_array_rectangle(&array);
            return 1;
        }

        int number = getter_rectangle(&array, 2, 1, &error);
        if (error)
        {
            print_error(error);
        }
        else
        {
            printf("%d\n", number);
        }

        print_array_rectangle(&array);

        delete_array_rectangle(&array);
    #endif // RECT_ARR

    #ifdef RECT_SIZE_ARR
        RectangleWithSizeArray array;
        
        error = input_array_rectangle_with_size(&array);

        if (error)
        {
            print_error(error);
            delete_array_rectangle_with_size(&array);
            return 1;
        }

        int number = 5;
        number = setter_rectangle_with_size(&array, 2, 0, number, &error);

        if (error)
        {
            print_error(error);
        }
        else
        {
            printf("%d\n", number);
        }

        

        print_array_rectangle_with_size(&array);

        delete_array_rectangle_with_size(&array);
    #endif // RECT_SIZE_ARR

    #ifdef TRIANGLE_ARR
        TriangleArray array;

        error = input_array_triangle(&array);

        if (error)
        {
            print_error(error);
            delete_array_triangle(&array);
            return 1;
        }

        int number = 5;
        number = setter_triangle(&array, 3, 0, number, &error);
        if (error)
        {
            print_error(error);
        }
        else
        {
            printf("%d\n", number);
        }

        print_array_triangle(&array);
        
        delete_array_triangle(&array);
    #endif // TRIANGLE_ARR
}

// naming, static, simple for, 3 .h, if error return in func or macros, data2 in struct
