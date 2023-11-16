/**
 * @file ordered_pair.h
 */

#ifndef ORDERED_PAIR_H
#define ORDERED_PAIR_H

#include "set.h"

/**
 * @typedef ordered_pair
 * @brief A typedef for ordered pairs represented using sets.
 */
typedef set ordered_pair;

ordered_pair OrderedPair(void *a, void *b);
void *getFirst(ordered_pair p);
void *getSecond(ordered_pair p);
bool isObjectAnOrderedPair(void *p);

#endif // ORDERED_PAIR_H
