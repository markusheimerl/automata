#include "deterministic_finite_automaton.h"

deterministic_finite_automaton DeterministicFiniteAutomaton(set states, set alphabet, delta_function delta, word start, set final_states)
{
    return NTuple(5, states, alphabet, delta, start, final_states);
}

deterministic_finite_automaton nfaDFA(nondeterministic_finite_automaton nfa) {}
