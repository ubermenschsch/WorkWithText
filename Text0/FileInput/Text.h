#ifndef TEXT_H
#define TEXT_H 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>


const size_t MAX_NAME_FILE_LENGHT = 255;

enum Error
{
    NO_ERROR                            = 0,
    OPEN_FILE_ERROR                     = 1,
    DATA_NULL_ERROR                     = 2,
    INPUT_SIZE_ALOTOF_PARAMETRS_ERROR   = 3,
    INPUT_SIZE_ANOTHER_SYMBOL_ERROR     = 4,
    INPUT_STRING_ALOTOF_PARAMETRS_ERROR = 5,
    INPUT_STRING_ANOTHER_SYMBOL_ERROR   = 6,
    CALLOC_ERROR                        = 7,
};

struct Data1
{
    int * data = nullptr;
    size_t size_x = 0;
    size_t size_y = 0;
};

int input_array1(Data1 * data1);
int input_size1(FILE * fp, Data1 * data1);
int input_data1(FILE * fp, Data1 * data1);
int input_data_string1(FILE * fp, Data1 * data1, int num_string);
void print_data1(Data1 * data1);

void print_error(int error);
void delete_array(Data1 * data1);

void input_size2(int * data2);
void input_data2(int * data2);
int input_data_string2(int * data2, int num_string);
void print_data2(int * data2);

int char_to_digit(char symbol);
int is_clear_input(FILE * fp);
void fill_zero(int * data2);

#endif // TEXT_H
