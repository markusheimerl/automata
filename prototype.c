#include "n_tuple.h"
#include "nondeterministic_finite_automaton.h"
#include "set.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void regexNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"xy|z"));
    printNFA(nfa);

    bool res = runNFA(nfa, letter_x);
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"xy"));
    assert(res == true);
    res = runNFA(nfa, letter_z);
    assert(res == true);
    res = runNFA(nfa, letter_y);
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"xyz"));
    assert(res == false);

    print(L"Regex xy|z NFA test successful\n\n");

    nfa = createRegexNFA(wordFromString(L"a*"));
    printNFA(nfa);

    res = runNFA(nfa, NULL);
    assert(res == true);
    res = runNFA(nfa, letter_a);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaaaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaaaaaa"));
    assert(res == true);
    res = runNFA(nfa, letter_b);
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ab"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ba"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"aba"));
    assert(res == false);

    print(L"Regex a* NFA test successful\n\n");
}

int main_automata(void)
{
    (void)setlocale(LC_ALL, "");
    regexNFATest();

    return 0;
}
