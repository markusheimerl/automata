#ifndef DETERMINISTIC_FINITE_AUTOMATON_H
#define DETERMINISTIC_FINITE_AUTOMATON_H

#include "nondeterministic_finite_automaton.h"
#include "delta_function.h"
#include "letter.h"
#include "n_tuple.h"
#include "set.h"
#include "word.h"

typedef n_tuple deterministic_finite_automaton;

deterministic_finite_automaton DeterministicFiniteAutomaton(set states, set alphabet, delta_function delta, word start, set final_states);

deterministic_finite_automaton nfaDFA(nondeterministic_finite_automaton nfa);

#endif // DETERMINISTIC_FINITE_AUTOMATON_H