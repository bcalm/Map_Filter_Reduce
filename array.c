#include "array.h"

Int_Array *create_array(int size){
  Int_Array *array = malloc(sizeof(Int_Array));
  if(array == NULL){
    return NULL;
  }
  array->values = size ? malloc(size * sizeof(int)) : NULL;
  array->length = size;
  return array;
}

Int_Array *map(function map_func, Int_Array* array){
  Int_Array *mapped_array = create_array(array->length);
  if(mapped_array == NULL || mapped_array->values == NULL){
    return NULL;
  }
  for (int idx = 0; idx < array->length; idx++)
  {
    mapped_array->values[idx] = (*map_func)(array->values[idx]);
  }
  return mapped_array;
}

Int_Array *filter(function filter_func, Int_Array* array){
  int count = 0;
  Int_Array *filtered_array = create_array(array->length);

  if(filtered_array == NULL || filtered_array->values == NULL){
    return NULL;
  }
  for (int idx = 0; idx < array->length; idx++)
  {
    if((*filter_func)(array->values[idx]))
    {
      printf("a as digit %d\n",array->values[idx]);
      filtered_array->values[count] = array->values[idx];
      count++;
    }
  }
  printf("a as digit %d\n",count);
  filtered_array->values = realloc(filtered_array->values, count * sizeof(int));
  filtered_array->length = count;
  return filtered_array;
}

int reduce(arithmetic_fn reducer, Int_Array *array, int accumulator){

  for (int i = 0; i < array->length; i++)
  {
    accumulator = (*reducer)(array->values[i], accumulator);  
  }
  return accumulator;
}