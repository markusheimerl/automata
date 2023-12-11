#include "n_tuple.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

n_tuple NTupleFromVoidPointerArray(void **contents)
{
    unsigned int n = *((unsigned int *)contents[0]);
    assert(n >= 2);
    contents = contents + 1;

    n_tuple t = OrderedPair(contents[0], contents[1]);

    for (unsigned int i = 2; i < n; i++)
    {
        t = OrderedPair(t, contents[i]);
    }

    return t;
}

n_tuple NTuple(unsigned int n, ...)
{
    void *contents[n + 1];
    contents[0] = &n;

    va_list args;
    va_start(args, n);

    for (unsigned int i = 0; i < n; i++)
    {
        contents[i + 1] = va_arg(args, void *);
    }

    va_end(args);

    return NTupleFromVoidPointerArray(contents);
}

void *getObjectByIndex(n_tuple t, unsigned int idx)
{
    unsigned int length = getLength(t);
    assert(idx < length);

    if (idx == 0 && length == 2)
    {
        return getFirst(t);
    }
    else if (idx == length - 1)
    {
        return getSecond(t);
    }
    else
    {
        return getObjectByIndex(getFirst(t), idx);
    }
}

unsigned int getLength(n_tuple t)
{
    void *first = getFirst(t);
    if (isObjectAnOrderedPair(first))
    {
        return 1 + getLength(first);
    }
    else
    {
        return 2;
    }
}
