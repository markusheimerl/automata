#include "delta_function.h"
#include "n_tuple.h"

delta_function DeltaFunction(void)
{
    return Function();
}

function addToDeltaFunction(delta_function f, word w, letter let, set to)
{
    set from = addToSet(Set(), w);
    from = addToSet(from, let);
    return addToFunction(f, from, to);
}

set getDeltaFunctionValue(delta_function f, word w, letter let)
{
    set from = addToSet(Set(), w);
    from = addToSet(from, let);
    return getFunctionValue(f, from);
}

word getWordFromDomainElement(set from)
{
    void *firstDrawFrom = drawFromSet(from);
    if (isObjectAnOrderedPair(firstDrawFrom))
    {
        return firstDrawFrom;
    }
    else
    {
        return drawFromSet(from);
    }
}

letter getLetterFromDomainElement(set from)
{
    void *firstDrawFrom = drawFromSet(from);
    if (isObjectAnOrderedPair(firstDrawFrom))
    {
        return drawFromSet(from);
    }
    else
    {
        return firstDrawFrom;
    }
}