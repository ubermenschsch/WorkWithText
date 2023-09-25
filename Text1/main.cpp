#include "Text.h"

int main()
{
    int error = NO_ERROR;

    char text[MAX_NUM_STRING][MAX_LENGHT] = {0};

    error = input_text(text);

    if (error)
    {
        print_error(error);
        return 1;
    }

    print_text(text);
}