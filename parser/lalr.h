#ifndef LALR_H
#define LALR_H

#include "n_tuple.h"

typedef n_tuple lalr;

lalr LALR(unsigned int n, ...);
void parse(lalr parser, const wchar_t *str);
void freeLALR(lalr parser);

#endif // LALR_H
