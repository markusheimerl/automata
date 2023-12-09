#include "n_tuple.h"
#include "nondeterministic_finite_automaton.h"
#include "set.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void regexNFATest(void)
{
    /*
    Q = {q1llrirl, q0irl, q0l, q1rllrirl, q0lirl, q0irll, q1irl, q1rl, q0, q1rlrirl, q0rlrirl, q0rll, q1l, q0rllrirl, q0r, q1r, q0rirl, q0rrirl, q1illlrirl, q1lll, q1lrirl, q0rl, q1lllrirl, q0lll, q1rll, q0illlrirl, q0lrirl, q0lllrirl, q0ll, q1ll, q1, q1rrirl, q0llrirl, q1lirl, q1rirl, q1irll}
    Σ = {b, r, t, a}
    δ = {
        ({q0lrirl, ε}, {q0llrirl}),
        ({q1rllrirl, ε}, {q1llrirl}),
        ({q1r, ε}, {q1}),
        ({q1rll, ε}, {q1ll}),
        ({q0illlrirl, t}, {q1illlrirl}),
        ({q1rlrirl, ε}, {q1lrirl}),
        ({q0, ε}, {q0l, q0r}),
        ({q0irll, t}, {q1irll}),
        ({q0r, b}, {q1r}),
        ({q0l, ε}, {q0ll}),
        ({q0lll, a}, {q1lll}),
        ({q0lllrirl, ε}, {q0illlrirl, q1lllrirl}),
        ({q1lllrirl, ε}, {q0rllrirl}),
        ({q0ll, ε}, {q0lll}),
        ({q1rl, ε}, {q1l}),
        ({q0rlrirl, a}, {q1rlrirl}),
        ({q1lll, ε}, {q0rll}),
        ({q0rll, ε}, {q1rll, q0irll}),
        ({q1l, ε}, {q1}),
        ({q0irl, ε}, {q0lirl, q0rirl}),
        ({q1rrirl, ε}, {q1rirl}),
        ({q1illlrirl, ε}, {q0illlrirl, q1lllrirl}),
        ({q1lrirl, ε}, {q0rrirl}),
        ({q0lirl, r}, {q1lirl}),
        ({q1rirl, ε}, {q1irl}),
        ({q1lirl, ε}, {q1irl}),
        ({q1ll, ε}, {q0rl}),
        ({q0rrirl, b}, {q1rrirl}),
        ({q1irl, ε}, {q1rl, q0irl}),
        ({q0rirl, ε}, {q0lrirl}),
        ({q0llrirl, ε}, {q0lllrirl}),
        ({q0rllrirl, a}, {q1rllrirl}),
        ({q1llrirl, ε}, {q0rlrirl}),
        ({q0rl, ε}, {q1rl, q0irl}),
        ({q1irll, ε}, {q1rll, q0irll})
    }
    q = q0
    F = {q1}
    Regex at*(r|t*aab)*|b NFA test successful
    */

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
