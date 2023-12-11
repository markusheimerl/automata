#ifndef NTUPLE_H
#define NTUPLE_H

#include "ordered_pair.h"

typedef ordered_pair n_tuple;

n_tuple NTuple(unsigned int n, ...);
n_tuple NTupleFromVoidPointerArray(void **contents);
void *getObjectByIndex(n_tuple t, unsigned int idx);
unsigned int getLength(n_tuple t);

#endif // NTUPLE_H
