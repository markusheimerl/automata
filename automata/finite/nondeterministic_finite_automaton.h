#ifndef NONDETERMINISTIC_FINITE_AUTOMATON_H
#define NONDETERMINISTIC_FINITE_AUTOMATON_H

#include "delta_function.h"
#include "letter.h"
#include "n_tuple.h"
#include "set.h"
#include "word.h"

typedef n_tuple nondeterministic_finite_automaton;

nondeterministic_finite_automaton NondeterministicFiniteAutomaton(set states, set alphabet, delta_function delta, word start, set final_states);
void printNFA(nondeterministic_finite_automaton);
bool runNFA(nondeterministic_finite_automaton, void *);

nondeterministic_finite_automaton letterNFA(letter);
nondeterministic_finite_automaton concatinationNFA(nondeterministic_finite_automaton, nondeterministic_finite_automaton);
nondeterministic_finite_automaton unionNFA(nondeterministic_finite_automaton, nondeterministic_finite_automaton);
nondeterministic_finite_automaton iterationNFA(nondeterministic_finite_automaton);
nondeterministic_finite_automaton regexNFA(word);

#endif