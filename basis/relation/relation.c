#include "relation.h"
#include "n_tuple.h"
#include <assert.h>

relation Relation()
{
    return Set();
}

relation addToRelation(relation r, void *from, void *to)
{
    return addToSet(r, NTuple(2, from, to));
}

set getRelationValue(relation r, void *from)
{
    set result = Set();
    for (unsigned int i = 0; i < getCardinality(r); i++)
    {
        n_tuple t = drawFromSet(r);
        if (getObjectByIndex(t, 0) == from)
        {
            result = addToSet(result, getObjectByIndex(t, 1));
        }
    }

    return result;
}