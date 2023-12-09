#include "n_tuple.h"
#include "nondeterministic_finite_automaton.h"
#include "set.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void regexNFATest1(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"ba*"));
    printNFA(nfa);

    bool res = runNFA(nfa, NULL);
    assert(res == false);
    res = runNFA(nfa, letter_b);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"ba"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"baa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"baaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"baaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"baaaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"baaaaaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"baaaaaaa"));
    assert(res == true);
    res = runNFA(nfa, letter_b);
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ab"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"aba"));
    assert(res == false);

    print(L"Regex ba* NFA test successful\n\n");
}

void regexNFATest2(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"b|a*"));
    printNFA(nfa);

    bool res = runNFA(nfa, NULL);
    assert(res == true);
    res = runNFA(nfa, letter_b);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"ba"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"baa"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"baaa"));
    assert(res == false);
    res = runNFA(nfa, letter_a);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaa"));
    assert(res == true);

    print(L"Regex b|a* NFA test successful\n\n");
}

void regexNFATest3(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"abc|a*"));
    printNFA(nfa);

    bool res = runNFA(nfa, NULL);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"abc"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"ba"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"baa"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"baaa"));
    assert(res == false);
    res = runNFA(nfa, letter_a);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaa"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaaa"));
    assert(res == true);

    print(L"Regex b|a* NFA test successful\n\n");
}

void regexNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"a*b"));
    printNFA(nfa);

    bool res = runNFA(nfa, NULL);
    assert(res == false);
    res = runNFA(nfa, letter_b);
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"ba"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ab"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aab"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"aaab"));
    assert(res == true);

    print(L"Regex a*b NFA test successful\n\n");
}

int main_automata(void)
{
    (void)setlocale(LC_ALL, "");

    nondeterministic_finite_automaton nfa = createRegexNFA(wordFromString(L"a*"));
    printNFA(nfa);

    regexNFATest3();

    return 0;
}
