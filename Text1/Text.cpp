#include "Text.h"

int input_text(char text[][MAX_LENGHT])
{
    int error = NO_ERROR;

    if (text == nullptr)
        return TEXT_NULL_ERROR;
    
    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    printf("Input name of file:\n");
    scanf("%s", file_name);

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    int num_string = 0;
    int num_symbol_in_string = 0;
    char * empty_string = nullptr;

    while (num_string < MAX_NUM_STRING )
    {
        empty_string = fgets(text[num_string], MAX_LENGHT, fp);

        if (empty_string == nullptr)
            break;

        num_string++;
    }

    if (getc(fp) != EOF)
        return INPUT_STRING_ERROR;

    fclose(fp);

    return NO_ERROR;
}

void print_text(char text[][MAX_LENGHT])
{
    for (int num_string = 0; num_string < MAX_NUM_STRING; num_string++)
    {
        printf("%s", text[num_string]);
    }
}

void print_error(int error)
{
    assert(error);

    switch(error)
    {
    case OPEN_FILE_ERROR:
        printf("Fail of open file. Try another name.\n");
        break;
    case TEXT_NULL_ERROR:
        printf("Send null pointer of text. Check initialization of data.\n");
        break;
    case INPUT_STRING_ERROR:
        printf("Fail of input file data. Check max size and max number of string.\n");
        break;
    }
}