#include "nondeterministic_pushdown_automaton.h"

nondeterminisitc_pushdown_automaton NondeterministicPushDownAutomaton(set states, set input_alphabet, set stack_alphabet, function delta_function, word start_state, set final_states){
    return NTuple(6, states, input_alphabet, stack_alphabet, delta_function, start_state, final_states);
}