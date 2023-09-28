#include "Text.h"

// static int file_num_string(FILE * fp);
static long file_size(FILE * fp);
static void cout_num_string(Text * text);
static int input_data(Text * text);

void input_filename(char * file_name)
{
    printf("Input name of file:\n");
    scanf("%s", file_name);
}

int input_text(Text * text, char * filename)
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

    printf("1\n");

    cout_num_string(text);

    printf("1\n");

    text->data = (char**)calloc(text->num_string, sizeof(char*));

    if (text->data == nullptr)
        return ALLOC_DATA_ERROR;

    printf("1\n");

    error = input_data(text);

    if (error)
        return INPUT_STRING_ERROR;   

    printf("1\n"); 

    return NO_ERROR;
}

static long file_size(FILE * fp)
{
    int error = 0;

    error = fseek(fp, 0L, SEEK_END);

    if (error != 0)
        return 0;
    
    long file_size = ftell(fp);

    if (file_size == -1L)
        return 0;

    error = fseek(fp, 0L, SEEK_SET);

    if (error != 0)
        return 0;
    
    return file_size;
}

// static int file_num_string(FILE * fp)
// {
//     assert(fp != nullptr);

//     int num_string = 0;

//     char symbol = getc(fp);
//     while (symbol != EOF)
//     {
//         if (symbol == '\n')
//         {
//             num_string++;
//         }

//         symbol = getc(fp);
//     }

//     fseek(fp, 0L, SEEK_SET);

//     return num_string;
// }

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

void delete_text(Text * text)
{
    text->lenght = 0;
    text->num_string = 0;
    free(text->data);
    free(text->buffer);
    text = nullptr;
}