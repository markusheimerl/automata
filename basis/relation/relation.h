#ifndef RELATION_H
#define RELATION_H

#include "set.h"

typedef set relation;

relation Relation(void);
relation addToRelation(relation r, void *from, void *to);
set getRelationValue(relation r, void *from);

#endif // RELATION_H
