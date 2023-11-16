/**
 * @file set.h
 * @brief A public API for a set data structure, implemented using a hash table.
 *
 * This header file provides an interface for managing a set of objects.
 * Sets are implemented using a hash table to allow for fast insertion,
 * deletion, and lookup operations.
 */

#ifndef SET_H
#define SET_H

#include "hash_table.h"

/**
 * @typedef set
 * @brief A typedef for sets represented using hash tables.
 */
typedef struct hash_table_ *set;

/**
 * @fn set Set()
 * @brief Initialize a new set.
 *
 * Creates and returns a new set.
 *
 * @return A pointer to a new set.
 */
set Set(void);

/**
 * @fn set addToSet(set s, void *object)
 * @brief Add an object to a set.
 *
 * Adds a unique object to a given set.
 *
 * @param s A pointer to the set to which the object will be added.
 * @param object The object to add to the set.
 * @return A pointer to the modified set.
 */
set addToSet(set s, void *object);

/**
 * @fn bool isElementOf(set s, void *object)
 * @brief Check if an object is an element of a set.
 *
 * @param s A pointer to the set in which to search for the object.
 * @param object The object to search for.
 * @return True if the object is in the set, false otherwise.
 */
bool isElementOf(set s, void *object);

/**
 * @fn set removeFromSet(set s, void *object)
 * @brief Remove an object from a set.
 *
 * Removes a specified object from the given set.
 *
 * @param s A pointer to the set from which to remove the object.
 * @param object The object to remove.
 * @return A pointer to the modified set.
 */
set removeFromSet(set s, void *object);

/**
 * @fn void *drawFromSet(set s)
 * @brief Draw an object from a set.
 *
 * Draws an arbitrary object from the set for inspection.
 *
 * @param s A pointer to the set from which to draw an object.
 * @return The object drawn from the set, or NULL if the set is empty.
 */
void *drawFromSet(set s);

/**
 * @fn unsigned int getCardinality(set s)
 * @brief Get the cardinality of a set.
 *
 * Returns the number of elements in the given set.
 *
 * @param s A pointer to the set whose cardinality is to be determined.
 * @return The number of elements in the set.
 */
unsigned int getCardinality(set s);

/**
 * @fn set unionSet(set s, set t)
 * @brief Compute the union of two sets.
 *
 * Computes the union of two sets, returning a new set containing all elements
 * in either set.
 *
 * @param s A pointer to the first set.
 * @param t A pointer to the second set.
 * @return A pointer to the union of the two sets.
 */
set unionSet(set s, set t);

bool isObjectASet(void *p);

#endif // SET_H
