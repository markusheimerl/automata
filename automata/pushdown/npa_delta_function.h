#ifndef NPA_DELTA_FUNCTION_H
#define NPA_DELTA_FUNCTION_H

#include "function.h"
#include "word.h"
#include "letter.h"

typedef function npa_delta_function;

npa_delta_function NPADeltaFunction(void);
npa_delta_function relationToNPADeltaFunction(relation delta_relation);
npa_delta_function addToNPADeltaFunction(npa_delta_function f, word w, letter let, set to);
set getNPADeltaFunctionValue(npa_delta_function f, word w, letter let);
word getWordFromNPADeltaFunctionDomainElement(set from);
letter getLetterFromNPADeltaFunctionDomainElement(set from);

#endif // NPA_DELTA_FUNCTION_H
