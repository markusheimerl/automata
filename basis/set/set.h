#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct hash_table *set;

set Set(void);
set addToSet(set s, void *object);
bool isElementOf(set s, void *object);
set removeFromSet(set s, void *object);
void *drawFromSet(set s);
unsigned int getCardinality(set s);
set unionSet(set s, set t);
bool isObjectASet(void *p);

#endif // SET_H
