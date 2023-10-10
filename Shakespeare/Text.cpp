#include "Text.h"

void ctor_text(Text * text)
{
    assert(text != nullptr);

    text->buffer      = nullptr;
    text->size_buffer = 0;
    text->data        = nullptr;
    text->num_string  = 0;
}

void dtor_text(Text * text)
{
    text->size_buffer = -1;
    text->num_string  = -1;

    free(text->buffer);
    free(text->data);

    text = nullptr;
}

static long file_size(FILE * fp);
static void cout_num_string(Text * text);
static int input_data(Text * text);

void input_filename(char * file_name)
{
    printf("Input name of file:\n");
    scanf("%s", file_name);
}

int input_text(Text * text, const char * filename)
{
    int error = NO_ERROR;

    if (text == nullptr)
        return TEXT_NULL_ERROR;

    FILE * fp = nullptr;
    fp = fopen(filename, "r");
    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    text->size_buffer = file_size(fp);
    if (text->size_buffer == 0)
        return FILE_SIZE_ERROR;
    
    text->buffer = (char*)calloc(text->size_buffer, sizeof(char));
    if (text->buffer == nullptr)
        return ALLOC_BUFF_ERROR;
    
    fread(text->buffer, sizeof(char), text->size_buffer, fp);
    fclose(fp);

    cout_num_string(text);

    text->data = (char**)calloc(text->num_string, sizeof(char*));
    if (text->data == nullptr)
        return ALLOC_DATA_ERROR;

    error = input_data(text);
    if (error)
        return INPUT_STRING_ERROR;

    return NO_ERROR;
}

static long file_size(FILE * fp)
{
    int error = 0;

    error = fseek(fp, 0L, SEEK_END);
    if (error != NO_ERROR)
        return 0;
    
    long file_size = ftell(fp);
    if (file_size == -1L)
        return 0;

    error = fseek(fp, 0L, SEEK_SET);
    if (error != 0)
        return 0;

    return file_size;
}

static void cout_num_string(Text * text)
{
    assert(text != nullptr);
    assert(text->buffer != nullptr);
    assert(text->size_buffer != 0);
    assert(text->num_string == 0);

    text->num_string = 1;

    char symbol = 0;
    for (int num_element = 0; num_element < text->size_buffer; num_element++)
    {
        symbol = text->buffer[num_element];
        if (symbol == '\n')
        {
            text->num_string++;
        }
    }
}

static int input_data(Text * text)
{
    assert(text != nullptr);
    assert(text->buffer != nullptr);
    assert(text->data != nullptr);
    assert(text->num_string != 0);

    char symbol = 0;
    int num_element = 0;
    for (int i = 0; i < text->num_string; i++)
    {
        text->data[i] = text->buffer + num_element;
        
        symbol = text->buffer[num_element];
        while (symbol != '\n' && num_element < text->size_buffer)
        {
            num_element++;
            symbol = text->buffer[num_element];
        }
        
        text->buffer[num_element] = '\0';
        num_element++;
    }

    if (num_element == text->size_buffer)
        return INPUT_STRING_ERROR;

    return NO_ERROR;
}

// void print_text(Text * text)
// {
//     assert(text != nullptr);
//     assert(text->data != nullptr);

//     for (int i = 0; i < text->num_string; i++)
//     {
//         printf("%s\n", text->data[i]);
//     }
// }

int output_text(Text * text)
{
    assert(text != nullptr);
    assert(text->data != nullptr);

    FILE * fp = fopen("output.txt", "w");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    for (int i = 0; i < text->num_string; i++)
    {
        fprintf(fp, "%s\n", text->data[i]);
    }

    return NO_ERROR;
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
    case FILE_SIZE_ERROR:
        printf("Fail of cout size of file.\n");
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