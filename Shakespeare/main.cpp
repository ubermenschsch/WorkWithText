#include "Qsort.h"
#include "Text.h"

int main()
{
    int error = NO_ERROR;

    char filename[MAX_NAME_FILE_LENGHT] = {};
    input_filename(filename);

    Text text;
    ctor_text(&text);

    error = input_text(&text, filename);
    if (error)
    {
        print_error(error);
        dtor_text(&text);
        return 1;
    }

    sort(text.data, text.num_string, sizeof(char*), comparator_string);

    error = output_text(&text);
    if (error)
    {
        print_error(error);
        dtor_text(&text);
        return 1;
    }

    dtor_text(&text);
}