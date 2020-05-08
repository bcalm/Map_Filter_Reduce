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

#define IS_MEMORY_NOT_ALLOCATED(array) if(array == NULL || array->values == NULL)

typedef enum
{
  False,
  True
} Boolean;

typedef int (*Mapper)(int);
typedef Boolean (*Predicate)(int);
typedef int(*Reducer)(int, int);


Int_Array *map(Mapper, Int_Array *); 
Int_Array *filter(Predicate, Int_Array *); 
int reduce(Reducer, Int_Array *, int); 
Int_Array *create_array(int size);

#endif

