#ifndef NTUPLE_H
#define NTUPLE_H

#include "ordered_pair.h"

typedef ordered_pair n_tuple;

/**
 * @fn n_tuple NTuple(unsigned int n, ...)
 * @brief Creates an n-tuple from a given number of elements.
 *
 * Initializes and returns an n-tuple with the specified elements.
 *
 * @param n The number of elements in the tuple.
 * @param ... Variable-length argument list containing the elements.
 * @return A pointer to the initialized n-tuple.
 */
n_tuple NTuple(unsigned int n, ...);

/**
 * @fn n_tuple NTupleFromVoidPointerArray(void **contents)
 * @brief Creates an n-tuple from a void pointer array.
 *
 * Initializes and returns an n-tuple using the specified void pointer array.
 * The first element of the array should point to the size of the tuple.
 *
 * @param contents The void pointer array containing the elements.
 * @return A pointer to the initialized n-tuple.
 */
n_tuple NTupleFromVoidPointerArray(void **contents);

/**
 * @fn void *getObjectByIndex(n_tuple t, unsigned int idx)
 * @brief Retrieves an object from the n-tuple by index.
 *
 * Returns the object at the specified index in the given n-tuple.
 *
 * @param t A pointer to the n-tuple.
 * @param idx The index of the object to retrieve.
 * @return The object at the specified index.
 */
void *getObjectByIndex(n_tuple t, unsigned int idx);

/**
 * @fn unsigned int getLength(n_tuple t)
 * @brief Returns the length of the n-tuple.
 *
 * Retrieves the number of elements in the given n-tuple.
 *
 * @param t A pointer to the n-tuple.
 * @return The number of elements in the n-tuple.
 */
unsigned int getLength(n_tuple t);

#endif // NTUPLE_H
