#include "Text.h"

int main()
{
    int error = NO_ERROR;

    Text text;

    error = input_text(&text);

    if (error)
    {
        print_error(error);
        delete_text(&text);
        return 1;
    }

    print_text(&text);

    delete_text(&text);
}