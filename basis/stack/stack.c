#include "stack.h"
#include "ordered_pair.h"

stack Stack(void)
{
    return Set();
}
/*
void push(stack s, void *e)
{
    unsigned int height = 0;
    for (unsigned int i = 0; i < getCardinality(s); i++)
    {
        ordered_pair p = drawFromSet(s);
        unsigned int h = getSecond(p);
        if (h > height)
            height = h;
    }
    addToSet(s, OrderedPair(e, height + 1));
}

void *pop(stack s)
{
    unsigned int height = 0;
    void *top;
    for (unsigned int i = 0; i < getCardinality(s); i++)
    {
        ordered_pair p = drawFromSet(s);
        unsigned int h = getSecond(p);
        if (h > height)
        {
            height = h;
            top = p;
        }
    }
    removeFromSet(s, top);
    return top;
}
*/