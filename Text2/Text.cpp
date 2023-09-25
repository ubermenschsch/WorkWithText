#include "Text.h"

static int file_num_string(FILE * fp);
static int input_data(FILE * fp, Text * text);

int input_text(Text * text)
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

    text->num_string = file_num_string(fp);

    if (text->num_string == 0)
        return FILE_NUM_STRING_ERROR;
    
    text->data = (char*)calloc(text->num_string * text->lenght, sizeof(char));

    if (text->data == nullptr)
        return ALLOC_ERROR;

    fseek(fp, 0L, SEEK_SET);
    
    error = input_data(fp, text);

    if (error)
        return INPUT_STRING_ERROR;
    
    fclose(fp);

    return NO_ERROR;
}

static int input_data(FILE * fp, Text * text)
{
    assert(fp != nullptr);
    assert(text != nullptr);
    assert(text->num_string != 0);

    char * empty_string = nullptr;
    for (int i = 0; i <= text->num_string; i++)
    {
        // printf("%d\n", getc(fp));
        // printf("%d) ", i);
        empty_string = fgets(text->data + i * text->lenght, text->lenght, fp);
        printf("%s", text->data + i * text->lenght);
        // printf("%s\n", empty_string);
        // if (empty_string == nullptr)
        //     printf("%d\n", i);
        //     break;
    }
    // printf("%s", text->data);
    if (getc(fp) != EOF)
        return INPUT_STRING_ERROR;

    return NO_ERROR;
}

static int file_num_string(FILE * fp)
{
    assert(fp != nullptr);

    int num_string = 0;

    char symbol = getc(fp);
    while (symbol != EOF)
    {
        if (symbol == '\n')
        {
            num_string++;
        }

        symbol = getc(fp);
    }

    return num_string;
}

void print_text(Text * text)
{
    assert(text != nullptr);
    assert(text->data != nullptr);

    for (int i = 0; i <= text->num_string; i++)
    {
        printf("%s", text->data + i * text->lenght);
    }
}

void print_error(int error)
{
    assert(error);

    switch (error)
    {
    case TEXT_NULL_ERROR:
        printf("Pointer on text struct is NULL.\n");
        break;
    case OPEN_FILE_ERROR:
        printf("Fail of open file. try another name.\n");
        break;
    case FILE_NUM_STRING_ERROR:
        printf("Zero strings in file.\n");
        break;
    case ALLOC_ERROR:
        printf("Fail of alloc memory.\n");
        break;
    case INPUT_STRING_ERROR:
        printf("Fail of input file.\n");
        break;
    }
}

void delete_text(Text * text)
{
    text->lenght = 0;
    text->num_string = 0;
    free(text->data);
    text = nullptr;
}