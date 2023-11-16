#include "ordered_pair.h"
#include <assert.h>
#include <stddef.h>

ordered_pair OrderedPair(void *a, void *b)
{
    set s_a = Set();
    s_a = addToSet(s_a, a);

    set s_b = Set();
    s_b = addToSet(s_b, a);
    s_b = addToSet(s_b, b);

    ordered_pair p = Set();
    p = addToSet(p, s_a);
    p = addToSet(p, s_b);

    return p;
}

void *getFirst(ordered_pair p)
{
    /* special case */
    if (getCardinality(p) == 1)
    {
        set s = drawFromSet(p);
        if (getCardinality(s) == 1)
        {
            return drawFromSet(s);
        }
    }

    for (unsigned int i = 0; i < 2; i++)
    {
        set s = drawFromSet(p);
        if (getCardinality(s) == 1)
        {
            return drawFromSet(s);
        }
    }

    return NULL;
}

void *getSecond(ordered_pair p)
{
    void *first = getFirst(p);

    /* special case */
    if (getCardinality(p) == 1)
    {
        set s = drawFromSet(p);
        if (getCardinality(s) == 1)
        {
            return first;
        }
    }

    for (unsigned int i = 0; i < 2; i++)
    {
        set s = drawFromSet(p);
        if (getCardinality(s) == 2)
        {
            void *e = drawFromSet(s);
            if (e != first)
                return e;
            else
                return drawFromSet(s);
        }
    }

    return NULL;
}

bool isObjectAnOrderedPair(void *p)
{
    if (!isObjectASet(p))
        return false;

    /* special case */
    if (getCardinality(p) == 1)
    {
        set s = drawFromSet(p);
        if (!isObjectASet(s))
        {
            return false;
        }
        else if (getCardinality(s) != 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    set s = p;
    if (getCardinality(s) != 2)
        return false;

    set t1 = drawFromSet(s);
    set t2 = drawFromSet(s);

    if (!isObjectASet(t1) || !isObjectASet(t2))
        return false;

    if (getCardinality(t1) == 1)
    {
        if (getCardinality(t2) != 2)
            return false;

        if (!isElementOf(t2, drawFromSet(t1)))
            return false;
    }
    else if (getCardinality(t1) == 2)
    {
        if (getCardinality(t2) != 1)
            return false;

        if (!isElementOf(t1, drawFromSet(t2)))
            return false;
    }

    return true;
}