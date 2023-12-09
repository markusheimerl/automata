#include "n_tuple.h"
#include "nondeterministic_finite_automaton.h"
#include "set.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void regexNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(Word(4, letter_x, letter_y, letter_bar, letter_z));
    printNFA(nfa);

    bool res = runNFA(nfa, letter_x);
    assert(res == false);
    res = runNFA(nfa, Word(2, letter_x, letter_y));
    assert(res == true);
    res = runNFA(nfa, letter_z);
    assert(res == true);
    res = runNFA(nfa, letter_y);
    assert(res == false);
    res = runNFA(nfa, Word(3, letter_x, letter_y, letter_z));
    assert(res == false);

    print(L"Regex xy|z NFA test successful\n\n");
}

int main_automata(void)
{
    (void)setlocale(LC_ALL, "");
    regexNFATest();

    return 0;
}
