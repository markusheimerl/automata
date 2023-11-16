#include "function.h"
#include "n_tuple.h"

function Function()
{
    return Relation();
}

function addToFunction(function f, void *from, void *to)
{
    for (unsigned int i = 0; i < getCardinality(f); i++)
    {
        void *from_i = getObjectByIndex(drawFromSet(f), 0);
        if (from_i == from)
        {
            return f;
        }
    }

    return addToRelation(f, from, to);
}

void *getFunctionValue(function f, void *from)
{
    return drawFromSet(getRelationValue(f, from));
}
