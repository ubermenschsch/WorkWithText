#include "Text.h"

static size_t file_num_string(FILE * fp);
static int input_data(FILE * fp, Text * text);

void input_filename(char * file_name)
{
    printf("Input name of file:\n");
    scanf("%s", file_name);
}

int input_text(Text * text, char * file_name)
{
    int error = NO_ERROR;

    if (text == nullptr)
        return TEXT_NULL_ERROR;

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    text->num_string = file_num_string(fp);

    if (text->num_string == 0)
        return FILE_NUM_STRING_ERROR;
    
    text->buffer = (char*)calloc(text->lenght, sizeof(char));
    text->data = (char**)calloc(text->num_string, sizeof(char*));

    if (text->buffer == nullptr)
        return ALLOC_BUFF_ERROR;
    if (text->data == nullptr)
        return ALLOC_DATA_ERROR;
    
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

    for (int i = 0; i < text->num_string; i++)
    {
        getline(&text->buffer, &text->lenght, fp);
        text->data[i] = strdup(text->buffer);
    }

     if (getc(fp) != EOF)
        return INPUT_STRING_ERROR;

    return NO_ERROR;
}

static size_t file_num_string(FILE * fp)
{
    assert(fp != nullptr);

    size_t num_string = 0;

    char symbol = getc(fp);
    while (symbol != EOF)
    {
        if (symbol == '\n')
        {
            num_string++;
        }

        symbol = getc(fp);
    }

    fseek(fp, 0L, SEEK_SET);

    return num_string;
}

void print_text(Text * text)
{
    assert(text != nullptr);
    assert(text->data != nullptr);

    for (int i = 0; i < text->num_string; i++)
    {
        printf("%s", text->data[i]);
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
    case ALLOC_BUFF_ERROR:
        printf("Fail of alloc memory for buffer.\n");
        break;
    case ALLOC_DATA_ERROR:
        printf("Fail of alloc memory for data.\n");
        break;
    case INPUT_STRING_ERROR:
        printf("Fail of input file.\n");
        break;
    }
}

void delete_text(Text * text)
{
    for (int i = 0; i < text->num_string; i++)
    {
        free(text->data[i]);
    }
    text->lenght = 0;
    text->num_string = 0;
    free(text->data);
    free(text->buffer);
    text = nullptr;
}