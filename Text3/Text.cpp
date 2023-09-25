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
    
    text->buffer = (char*)calloc(text->num_string * text->lenght, sizeof(char));
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

    char symbol = 0;
    int num_element = 0;
    for (int i = 0; i < text->num_string; i++)
    {
        text->data[i] = text->buffer + num_element;

        symbol = getc(fp);
        while (symbol != '\n')
        {
            text->buffer[num_element] = symbol;

            symbol = getc(fp);
            num_element++;
        }
        
        text->buffer[num_element] = '\0';
        num_element++;
    }

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

    fseek(fp, 0L, SEEK_SET);

    return num_string;
}

void print_text(Text * text)
{
    assert(text != nullptr);
    assert(text->data != nullptr);

    for (int i = 0; i < text->num_string; i++)
    {
        printf("%s\n", text->data[i]);
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
    text->lenght = 0;
    text->num_string = 0;
    free(text->data);
    free(text->buffer);
    text = nullptr;
}