#ifndef DELTA_FUNCTION_H
#define DELTA_FUNCTION_H

#include "function.h"
#include "word.h"
#include "letter.h"

typedef function delta_function;

delta_function DeltaFunction(void);
delta_function relationToDeltaFunction(relation delta_relation);
delta_function addToDeltaFunction(delta_function f, word w, letter let, set to);
set getDeltaFunctionValue(delta_function f, word w, letter let);
word getWordFromDomainElement(set from);
letter getLetterFromDomainElement(set from);

#endif // DELTA_FUNCTION_H
