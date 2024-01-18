#ifndef NFA_DELTA_FUNCTION_H
#define NFA_DELTA_FUNCTION_H

#include "function.h"
#include "word.h"
#include "letter.h"

typedef function nfa_delta_function;

nfa_delta_function NFADeltaFunction(void);
nfa_delta_function relationToNFADeltaFunction(relation delta_relation);
nfa_delta_function addToNFADeltaFunction(nfa_delta_function f, word w, letter let, set to);
set getNFADeltaFunctionValue(nfa_delta_function f, word w, letter let);
word getWordFromNFADeltaFunctionDomainElement(set from);
letter getLetterFromNFADeltaFunctionDomainElement(set from);

#endif // NFA_DELTA_FUNCTION_H
