#include "array.h"

Int_Array *create_array(int size){
  Int_Array *array = malloc(sizeof(Int_Array));
  if(array == NULL){
    return NULL;
  }

  array->values = malloc(size * sizeof(int));

  if(array->values == NULL){
    return NULL;
  }

  array->length = size;
  return array;
}

Int_Array *map(function mapper, Int_Array* array){
  Int_Array *mapped_array = create_array(array->length);
  if(mapped_array == NULL){
    return NULL;
  }
  for (int idx = 0; idx < array->length; idx++)
  {
    mapped_array->values[idx] = (*mapper)(array->values[idx]);
  }
  return mapped_array;
}