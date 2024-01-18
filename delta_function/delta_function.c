#include "delta_function.h"
#include "n_tuple.h"

nfa_delta_function NFADeltaFunction(void)
{
    return Function();
}

nfa_delta_function relationToNFADeltaFunction(relation delta_relation)
{
    nfa_delta_function delta = NFADeltaFunction();
    for (unsigned int i = 0; i < getCardinality(delta_relation); i++)
    {
        n_tuple tuple = drawFromSet(delta_relation);
        set from = getObjectByIndex(tuple, 0);

        word state = getWordFromNFADeltaFunctionDomainElement(from);
        letter let = getLetterFromNFADeltaFunctionDomainElement(from);

        set new_to = Set();
        for (unsigned int j = 0; j < getCardinality(delta_relation); j++)
        {
            n_tuple tuple2 = drawFromSet(delta_relation);
            set from2 = getObjectByIndex(tuple2, 0);
            set to2 = getObjectByIndex(tuple2, 1);

            word state2 = getWordFromNFADeltaFunctionDomainElement(from2);
            letter let2 = getLetterFromNFADeltaFunctionDomainElement(from2);

            if (state == state2 && let == let2)
                new_to = unionSet(new_to, to2);
        }

        delta = addToNFADeltaFunction(delta, state, let, new_to);
    }

    for (unsigned int i = 0; i < getCardinality(delta_relation); i++)
    {
        n_tuple tuple = drawFromSet(delta_relation);
        set from = getObjectByIndex(tuple, 0);
        set to = getObjectByIndex(tuple, 1);

        word state = getWordFromNFADeltaFunctionDomainElement(from);
        letter let = getLetterFromNFADeltaFunctionDomainElement(from);

        bool exists = false;
        for (unsigned int j = 0; j < getCardinality(delta); j++)
        {
            n_tuple tuple2 = drawFromSet(delta);
            set from2 = getObjectByIndex(tuple2, 0);

            word state2 = getWordFromNFADeltaFunctionDomainElement(from2);
            letter let2 = getLetterFromNFADeltaFunctionDomainElement(from2);

            if (state == state2 && let == let2)
                exists = true;
        }

        if (!exists)
            delta = addToNFADeltaFunction(delta, state, let, to);
    }

    return delta;
}

nfa_delta_function addToNFADeltaFunction(nfa_delta_function f, word w, letter let, set to)
{
    set from = addToSet(Set(), w);
    from = addToSet(from, let);
    return addToFunction(f, from, to);
}

set getNFADeltaFunctionValue(nfa_delta_function f, word w, letter let)
{
    set from = addToSet(Set(), w);
    from = addToSet(from, let);
    return getFunctionValue(f, from);
}

word getWordFromNFADeltaFunctionDomainElement(set from)
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

letter getLetterFromNFADeltaFunctionDomainElement(set from)
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