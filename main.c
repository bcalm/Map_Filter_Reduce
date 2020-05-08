#include "array.h"

int increment_five(int number){
  return number + 5;
}

Boolean is_odd(int number){
  return number % 2;
}

int mul(int num1, int num2){
  return num1 * num2;
}

void print_array(Int_Array* array){
  REPEAT(array->length)
  {
    printf("%d term of array is %d\n", idx, array->values[idx]);
  }
}

int main(void)
{
  int numbers[] = DEFAULT_NUMBERS;
  int size = DEFAULT_LENGTH;
  Int_Array *array = create_array(size);
  IS_MEMORY_NOT_ALLOCATED(array){
    return 0;
  }
  array->values = numbers;
  Int_Array *mapped_array = map(&increment_five, array);
  Int_Array *filtered_array = filter(&is_odd, array);
  int sum_of_all = reduce(&mul, array, 1);
  print_array(mapped_array);
  print_array(filtered_array);
  printf("mul of all digits are %d\n", sum_of_all);
  return 0;
}