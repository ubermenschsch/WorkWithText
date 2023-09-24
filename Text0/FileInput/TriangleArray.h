#ifndef TRIANGLE_ARRAY_H
#define TRIANGLE_ARRAY_H 

// #include <stdio.h>

struct TriangleArray
{
    int * data = nullptr;
    int num_string = 0;
};

int input_array_triangle(TriangleArray * array);
int input_size_triangle(FILE * fp, TriangleArray * array);
int input_data_triangle(FILE * fp, TriangleArray * array);
int input_data_string_triangle(FILE * fp, TriangleArray * array, int num_string);
void print_array_triangle(const TriangleArray * array);
void delete_array_triangle(TriangleArray * array);
int getter_triangle(const TriangleArray * array, int num_string, int num_coloumn, int * error);
int setter_triangle(TriangleArray * array, int num_string, int num_coloumn, int new_data, int * error);

int num_elements_triangle(int num_string);

#endif // TRIANGLE_ARRAY_H