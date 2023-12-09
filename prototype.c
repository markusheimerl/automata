#include "n_tuple.h"
#include "nondeterministic_finite_automaton.h"
#include "set.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void regexNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"at*(r|t*aab)*|b"));
    printNFA(nfa);

    bool res = runNFA(nfa, letter_a);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"at"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"att"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"atr"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"attaab"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"atttaaab"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"attr"));
    assert(res == true);
    res = runNFA(nfa, letter_b);
    assert(res == true);

    // Test cases for strings that should not match
    res = runNFA(nfa, wordFromString(L"aa"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"rt"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ab"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ac"));
    assert(res == false);

    print(L"Regex at*(r|t*aab)*|b NFA test successful\n\n");
}

int main_automata(void)
{
    (void)setlocale(LC_ALL, "");
    regexNFATest();

    return 0;
}
