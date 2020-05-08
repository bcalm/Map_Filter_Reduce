#include "array.h"

Int_Array *create_array(int size){
  Int_Array *array = malloc(sizeof(Int_Array));
  if(array == NULL){
    return NULL;
  }
  array->length = size;
  return array;
}

int_ptr fill_data(int_ptr copy_to, int_ptr copy_from, int length)
{
  copy_to = length ? malloc(length * sizeof(int)): NULL;
  for (int idx = 0; idx < length; idx++)
  {
    copy_to[idx] = copy_from[idx];
  }
  return copy_to;
}

Int_Array *map(function map_func, Int_Array* array){
  Int_Array *mapped_array = create_array(array->length);
  if(mapped_array == NULL){
    return NULL;
  }
  int temp_array[array->length];
  for (int idx = 0; idx < array->length; idx++)
  {
    temp_array[idx] = (*map_func)(array->values[idx]);
  }
  mapped_array->values = fill_data(mapped_array->values, temp_array, array->length);
  return mapped_array;
}

Int_Array *filter(function filter_func, Int_Array* array){
  int temp_array[array->length];
  int count = 0;
  for (int idx = 0; idx < array->length; idx++)
  {
    if((*filter_func)(array->values[idx]))
    {
      temp_array[count] = array->values[idx];
      count++;
    }
  }
  Int_Array *filtered_array = create_array(count);
  if(filtered_array == NULL){
    return NULL;
  }
  filtered_array->values = fill_data(filtered_array->values, temp_array, count);
  return filtered_array;
}

int reduce(arithmetic_fn reducer, Int_Array *array, int accumulator){

  for (size_t i = 0; i < array->length; i++)
  {
    accumulator = (*reducer)(array->values[i], accumulator);  
  }
  return accumulator;
}