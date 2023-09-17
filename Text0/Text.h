#ifndef TEXT_H
#define TEXT_H 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

struct Data1
{
    int * data = nullptr;
    size_t size_x = 0;
    size_t size_y = 0;
};

void input_size(Data1 * data1);
void input_data(Data1 * data1);
int input_data_string(Data1 * data1, int num_string);
void print_data(Data1 * data1);

int char_to_digit(char symbol);
int is_clear_input(void);

#endif // TEXT_H