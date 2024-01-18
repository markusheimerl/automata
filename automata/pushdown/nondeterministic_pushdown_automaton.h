#ifndef NONDETERMINISTIC_PUSHDOWN_AUTOMATON_H
#define NONDETERMINISTIC_PUSHDOWN_AUTOMATON_H

#include "n_tuple.h"
#include "set.h"
#include "npa_delta_function.h"
#include "word.h"

typedef n_tuple nondeterminisitc_pushdown_automaton;

nondeterminisitc_pushdown_automaton NondeterministicPushDownAutomaton(set states, set input_alphabet, set stack_alphabet, npa_delta_function delta, word start_state, set final_states);

#endif // NONDETERMINISTIC_PUSHDOWN_AUTOMATON_H
