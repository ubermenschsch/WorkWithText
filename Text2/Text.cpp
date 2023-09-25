#include "Text.h"

static int filesize(FILE * fp, long * file_size);

#define ERR_RET(code)           \
        if(code) return code    \

int input_text(char * text)
{
    int error = NO_ERROR;

    // if (text == nullptr)
    //     return TEXT_NULL_ERROR;
    
    char file_name[MAX_NAME_FILE_LENGHT] = {0};
    printf("Input name of file:\n");
    scanf("%s", file_name);

    FILE * fp = nullptr;
    fp = fopen(file_name, "r");

    if (fp == nullptr)
        return OPEN_FILE_ERROR;

    long file_size = 0; 
    error = filesize(fp, &file_size);

    if (error)
        return FILE_SIZE_ERROR;
    
    text = (char*)calloc(file_size, sizeof(char));

    if (text == nullptr)
        return ALLOC_ERROR;

    char * position = text;
    char symbol = getc(fp);
    while (symbol != EOF)
    {
        while (symbol != '\n')
        {
            *position = symbol;
            symbol = getc(fp);
            position++;
        }
        *position = '\0';
        symbol = getc(fp);
        position++;
    }

    
    // error = input_size_rectangle(fp, array);

    // ERR_RET(error);

    // array->data = (int*)calloc(array->size_x * array->size_y, sizeof(int));

    // if (array->data == nullptr)
    //     return ALLOC_ERROR;

    // error = input_data_rectangle(fp, array);
    
    // ERR_RET(error);
    
    fclose(fp);

    return NO_ERROR;
}

print_text()

static int filesize(FILE * fp, long * file_size)
{
    int error = 0;

    error = fseek(fp, 0LL, SEEK_END);

    if (error == 0)
        return FILE_SIZE_ERROR;
    
    *file_size = ftell(fp);

    if (*file_size == -1L)
        return FILE_SIZE_ERROR;
    
    return NO_ERROR;
}