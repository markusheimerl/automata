#include "delta_function.h"
#include "n_tuple.h"

delta_function DeltaFunction(void)
{
    return Function();
}

delta_function relationToDeltaFunction(relation delta_relation)
{
    delta_function delta = DeltaFunction();
    for (unsigned int i = 0; i < getCardinality(delta_relation); i++)
    {
        n_tuple tuple = drawFromSet(delta_relation);
        set from = getObjectByIndex(tuple, 0);

        word state = getWordFromDomainElement(from);
        letter let = getLetterFromDomainElement(from);

        set new_to = Set();
        for (unsigned int j = 0; j < getCardinality(delta_relation); j++)
        {
            n_tuple tuple2 = drawFromSet(delta_relation);
            set from2 = getObjectByIndex(tuple2, 0);
            set to2 = getObjectByIndex(tuple2, 1);

            word state2 = getWordFromDomainElement(from2);
            letter let2 = getLetterFromDomainElement(from2);

            if (state == state2 && let == let2)
                new_to = unionSet(new_to, to2);
        }

        delta = addToDeltaFunction(delta, state, let, new_to);
    }

    for (unsigned int i = 0; i < getCardinality(delta_relation); i++)
    {
        n_tuple tuple = drawFromSet(delta_relation);
        set from = getObjectByIndex(tuple, 0);
        set to = getObjectByIndex(tuple, 1);

        word state = getWordFromDomainElement(from);
        letter let = getLetterFromDomainElement(from);

        bool exists = false;
        for (unsigned int j = 0; j < getCardinality(delta); j++)
        {
            n_tuple tuple2 = drawFromSet(delta);
            set from2 = getObjectByIndex(tuple2, 0);

            word state2 = getWordFromDomainElement(from2);
            letter let2 = getLetterFromDomainElement(from2);

            if (state == state2 && let == let2)
                exists = true;
        }

        if (!exists)
            delta = addToDeltaFunction(delta, state, let, to);
    }

    return delta;
}

delta_function addToDeltaFunction(delta_function f, word w, letter let, set to)
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