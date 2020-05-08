#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_NUMBERS {1, 2, 3, 4, 5}
#define DEFAULT_LENGTH 5

typedef int* int_ptr;

typedef struct{
  int_ptr values;
  int length;
} Int_Array;


typedef int (*function)(int);
typedef int(*arithmetic_fn)(int, int);


Int_Array *map(function, Int_Array *); 
Int_Array *filter(function, Int_Array *); 
int reduce(arithmetic_fn, Int_Array *, int); 
Int_Array *create_array(int size);
int_ptr fill_data(int_ptr, int_ptr, int);

#endif