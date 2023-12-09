#ifndef WORD_H
#define WORD_H

#include "letter.h"
#include "n_tuple.h"
#include <wchar.h>

typedef n_tuple word;

word Word(unsigned int n, ...);
word wordFromString(const wchar_t *str);
void print(const wchar_t *format, ...);
letter getLetterByIndex(word, unsigned int);
word getSubword(word, unsigned int, unsigned int);

#endif
