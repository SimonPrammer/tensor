// my header
// header files are somewhat like interfaces from TS.
// declare the structure in here, then implement in .c file

#ifndef MY_TENSOR1D_H
#define MY_TENSOR1D_H

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    float *data;
    int data_size;
    int ref_count;
} Storage;

// equivalent of tensor in Pytorch
typedef struct
{
    Storage *storage;
    int offset;
    int size;
    int stride;
    char *repr; // text representation of tensor

} Tensor;

Tensor *tensor_empty(int size);
int logical_to_physical(Tensor *t, int ix);
float tensor_getitem(Tensor *t, int ix);
Tensor *tensor_getitem_astensor(Tensor *t, int ix);
float tensor_item(Tensor *t);
void tensor_setitem(Tensor *t, int ix, float val);
Tensor *tensor_arange(int size);
char *tensor_to_string(Tensor *t);
void tensor_print(Tensor *t);
Tensor *tensor_slice(Tensor *t, int start, int end, int step);
Tensor *tensor_addf(Tensor *t, float val);
Tensor *tensor_add(Tensor *t1, Tensor *t2);
void tensor_incref(Tensor *t);
void tensor_decref(Tensor *t);
void tensor_free(Tensor *t);

#endif // MY_TENSOR1D_H