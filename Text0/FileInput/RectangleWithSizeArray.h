#ifndef RECTANGLE_WITH_SIZE_ARRAY_H 
#define RECTANGLE_WITH_SIZE_ARRAY_H 

struct RectangleWithSizeArray
{
    int * data = nullptr;
};

int input_array_rectangle_with_size(RectangleWithSizeArray * array);
int input_size_rectangle_with_size(FILE * fp, RectangleWithSizeArray * array);
int input_data_rectangle_with_size(FILE * fp, RectangleWithSizeArray * array);
int input_data_string_rectangle_with_size(FILE * fp, RectangleWithSizeArray * array, int num_string);
void print_array_rectangle_with_size(const RectangleWithSizeArray * array);
void delete_array_rectangle_with_size(RectangleWithSizeArray * array);
int getter_rectangle_with_size(const RectangleWithSizeArray * array, int num_string, int num_coloumn, int * error);
int setter_rectangle_with_size(RectangleWithSizeArray * array, int num_string, int num_coloumn, int new_data, int * error);
void fill_zero(RectangleWithSizeArray * array);

#endif // RECTANGLE_WITH_SIZE_ARRAY_H 