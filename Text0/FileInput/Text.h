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
    ALLOC_ERROR                         = 7,
    LEAVE_ARRAY_ERROR                   = 8,
};

struct Data1
{
    int * data = nullptr;
    size_t size_x = 0;
    size_t size_y = 0;
};

struct Data3
{
    int * data = nullptr;
    int num_string = 0;
};

int input_array1(Data1 * data1);
int input_size1(FILE * fp, Data1 * data1);
int input_data1(FILE * fp, Data1 * data1);
int input_data_string1(FILE * fp, Data1 * data1, int num_string);
void print_data1(Data1 * data1);
void delete_array1(Data1 * data1);
int getter1(Data1 * data1, int num_string, int num_coloumn, int * error);
int setter1(Data1 * data1, int num_string, int num_coloumn, int new_data, int * error);

int input_array2(int ** data2);
int input_size2(FILE * fp, int * data2);
int input_data2(FILE * fp, int * data2);
int input_data_string2(FILE * fp, int * data2, int num_string);
void print_data2(int * data2);
void delete_array2(int * data2);
int getter2(const int * data2, int num_string, int num_coloumn, int * error);
int setter2(int * data2, int num_string, int num_coloumn, int new_data, int * error);

int input_array3(Data3 * data3);
int input_size3(FILE * fp, Data3 * data3);
int input_data3(FILE * fp, Data3 * data3);
int input_data_string3(FILE * fp, Data3 * data3, int num_string);
void print_data3(Data3 * data3);
void delete_array3(Data3 * data3);
int getter3(const Data3 * data3, int num_string, int num_coloumn, int * error);
int setter3(Data3 * data3, int num_string, int num_coloumn, int new_data, int * error);

void print_error(int error);

int char_to_digit(char symbol);
int is_clear_input(FILE * fp);
void fill_zero(int * data2);
int num_triangle_elements(int num_string);

#endif // TEXT_H
