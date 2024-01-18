#ifndef STACK_H
#define STACK_H

#include "set.h"

typedef set stack;

stack Stack(void);
void push(stack s, void *e);
void *pop(stack s);

#endif // STACK_H