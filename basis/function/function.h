/**
 * @file function.h
 * @brief Public API for representing and manipulating mathematical functions.
 *
 * This header file offers a set-based interface for representing mathematical
 * functions as specific relations between sets, enabling you to create, query,
 * and modify these functions. Each element from the first set is precisely
 * mapped to a single element in the second set.
 *
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#include "relation.h"

/**
 * @typedef function
 * @brief A typedef for mathematical functions, represented as sets of pairs (n-tuples).
 */
typedef relation function;

/**
 * @fn function Function()
 * @brief Initializes a new empty function.
 *
 * Creates a new mathematical function represented as a set.
 *
 * @return A pointer to the initialized function.
 */
function Function(void);

/**
 * @fn function addToFunction(function f, void *from, void *to)
 * @brief Adds a new pair to the function.
 *
 * Inserts a new pair (from, to) into the given function.
 *
 * @param f A pointer to the function.
 * @param from The 'from' element in the pair.
 * @param to The 'to' element in the pair.
 * @return A pointer to the updated function.
 */
function addToFunction(function f, void *from, void *to);

/**
 * @fn void* getFunctionValue(function f, void *from)
 * @brief Retrieves the function value associated with a given input.
 *
 * Returns the value associated with the specified 'from' element.
 * This function assumes that each 'from' element in the function is mapped to exactly one 'to' element.
 *
 * @param f A pointer to the function.
 * @param from The 'from' element for which to find the corresponding 'to' element.
 * @return A pointer to the single 'to' element corresponding to the given 'from' element.
 */
void *getFunctionValue(function f, void *from);

#endif // FUNCTION_H
