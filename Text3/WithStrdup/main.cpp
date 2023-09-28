#include "Text.h"

int main()
{
    int error = NO_ERROR;

    Text text;

    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    input_filename(file_name);

    error = input_text(&text, file_name);

    if (error)
    {
        print_error(error);
        delete_text(&text);
        return 1;
    }

    print_text(&text);

    delete_text(&text);
}