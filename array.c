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
  copy_to = malloc(length * sizeof(int));
  for (int idx = 0; idx < length; idx++)
  {
    copy_to[idx] = copy_from[idx];
  }
  return copy_to;
}

Int_Array *map(function mapper, Int_Array* array){
  Int_Array *mapped_array = create_array(array->length);
  int temp_array[array->length];
  for (int idx = 0; idx < array->length; idx++)
  {
    temp_array[idx] = (*mapper)(array->values[idx]);
  }
  mapped_array->values = fill_data(mapped_array->values, temp_array, array->length);
  return mapped_array;
}

Int_Array *filter(function predicate, Int_Array* array){
  int temp_array[array->length];
  int count = 0;
  for (int idx = 0; idx < array->length; idx++)
  {
    if((*predicate)(array->values[idx]))
    {
      temp_array[count] = array->values[idx];
      count++;
    }
  }
  printf("a as digit %d\n",count);
  Int_Array *filtered_array = create_array(count);
  filtered_array->values = fill_data(filtered_array->values, temp_array, count);
  return filtered_array;
}

int reduce(arithmetic_fn reducer, Int_Array *array, int context){

  for (size_t i = 0; i < array->length; i++)
  {
    context = (*reducer)(array->values[i], context);  
  }
  return context;
}