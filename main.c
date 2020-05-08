#include "array.h"

int increment_five(int number){
  return number + 5;
}

int is_odd(int number){
  return number % 2;
}

void print_array(Int_Array* array){
  for (int idx = 0; idx < array->length; idx++)
  {
    printf("%d term of array is %d\n", idx, array->values[idx]);
  }
}

int main(void)
{
  int numbers[] = DEFAULT_NUMBERS;
  int size = DEFAULT_LENGTH;
  Int_Array *array = create_array(size);
  if(array == NULL){
    return 0;
  }
  array->values = copy_values(array->values, numbers, size);
  Int_Array *mapped_array = map(&increment_five, array);
  Int_Array *filtered_array = filter(&is_odd, array);
  print_array(mapped_array);
  print_array(filtered_array);
  return 0;
}