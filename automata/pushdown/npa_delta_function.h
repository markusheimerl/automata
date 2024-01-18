#ifndef NPA_DELTA_FUNCTION_H
#define NPA_DELTA_FUNCTION_H

#include "function.h"
#include "word.h"
#include "letter.h"

typedef function npa_delta_function;

npa_delta_function NPADeltaFunction(void);
npa_delta_function relationToNPADeltaFunction(relation delta_relation);
npa_delta_function addToNPADeltaFunction(npa_delta_function f, word w, letter let1, letter let2, set to);
set getNPADeltaFunctionValue(npa_delta_function f, word w, letter let1, letter let2);
word getWordFromNPADeltaFunctionDomainElement(set from);
letter getFirstLetterFromNPADeltaFunctionDomainElement(set from);
letter getSecondLetterFromNPADeltaFunctionDomainElement(set from);

#endif // NPA_DELTA_FUNCTION_H
