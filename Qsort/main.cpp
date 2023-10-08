#include "Qsort.h"
#include "Common.h"

// #define FILEINPUT
#define RANDTEST

#ifdef FILEINPUT
    #include "InputData.h"
#endif // FILEINPUT
#ifdef RANDTEST
    #include "RandomTest.h"
#endif // RANDTEST

int main()
{
    int error = NO_ERROR;

    #ifdef FILEINPUT
        char file_name[256] = {};
        error = input_filename(file_name);
        if (error)
        {
            print_error(error);
            return 1;
        }
    #endif // FILEINPUT

    Data data;
    ctor_data(&data);

    #ifdef FILEINPUT
        error = input_data(file_name, &data);
    #endif // FILEINPUT

    #ifdef RANDTEST
        error = set_data(&data);
    #endif // RANDTEST

    if (error)
    {
        print_error(error);
        dtor_data(&data);
        return 1;
    }

    sort(data.data, data.size, sizeof(elem_t), comparator_int);

    #ifdef FILEINPUT
        data_dump(data.data, data.size, 0, 0, 0);
    #endif // FILEINPUT

    #ifdef RANDTEST
        int result = check_correct(&data);
        error = print_result(result);

        if (error)
        {
            dtor_data(&data);
            return 1;
        }
    #endif // RANDTEST

    dtor_data(&data);
}