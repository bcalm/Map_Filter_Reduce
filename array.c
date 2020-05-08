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

Int_Array *map(Mapper map_func, Int_Array* array){
  Int_Array *mapped_array = create_array(array->length);
  IS_MEMORY_NOT_ALLOCATED(mapped_array){
    return NULL;
  }
  for (int idx = 0; idx < array->length; idx++)
  {
    mapped_array->values[idx] = (*map_func)(array->values[idx]);
  }
  return mapped_array;
}

Int_Array *filter(Predicate filter_func, Int_Array* array){
  int count = 0;
  Int_Array *filtered_array = create_array(array->length);

  IS_MEMORY_NOT_ALLOCATED(filtered_array){
    return NULL;
  }

  for (int idx = 0; idx < array->length; idx++)
  {
    if((*filter_func)(array->values[idx]))
    {
      filtered_array->values[count] = array->values[idx];
      count++;
    }
  }
  filtered_array->values = realloc(filtered_array->values, count * sizeof(int));
  filtered_array->length = count;
  return filtered_array;
}

int reduce(Reducer reduce_func, Int_Array *array, int accumulator){

  for (int i = 0; i < array->length; i++)
  {
    accumulator = (*reduce_func)(array->values[i], accumulator);  
  }
  return accumulator;
}