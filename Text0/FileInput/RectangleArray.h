#ifndef RECTANGLE_ARRAY_H
#define RECTANGLE_ARRAY_H 

struct RectangleArray
{
    int * data = nullptr;
    int size_x = 0;
    int size_y = 0;
};

int input_array_rectangle(RectangleArray * array);
void print_array_rectangle(const RectangleArray * array);
void delete_array_rectangle(RectangleArray * array);
int getter_rectangle(const RectangleArray * array, int num_string, int num_coloumn, int * error);
int setter_rectangle(RectangleArray * array, int num_string, int num_coloumn, int new_data, int * error);

#endif // RECTANGLE_ARRAY