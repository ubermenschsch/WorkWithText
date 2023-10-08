#include "Common.h"

void ctor_data(Data * data)
{
    data->data = nullptr;
    data->size = 0;
}

void dtor_data(Data * data)
{
    free(data->data);
    data->size = -1;
}