#ifndef DETERMINISTIC_FINITE_AUTOMATON_H
#define DETERMINISTIC_FINITE_AUTOMATON_H

#include "delta_function.h"
#include "letter.h"
#include "n_tuple.h"
#include "set.h"
#include "word.h"

typedef n_tuple deterministic_finite_automaton;

deterministic_finite_automaton DeterministicFiniteAutomaton(set states, set alphabet, delta_function delta, word start, set final_states);

#endif // DETERMINISTIC_FINITE_AUTOMATON_H