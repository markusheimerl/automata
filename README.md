# nondeterministic finite automata
A nondeterministic finite automata library

``` C
#include "nondeterministic_finite_automaton.h"
#include <assert.h>
#include <locale.h>

void regexNFATest(void)
{
    // Simpler regex: (ab|cd)*(ef|gh)
    nondeterministic_finite_automaton nfa = regexNFA(wordFromString(L"(ab|cd)*(ef|gh)"));
    printNFA(nfa);

    // Test cases for strings that should match
    bool res = runNFA(nfa, wordFromString(L"abef"));
    (void)res;
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"cdef"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"abcdgh"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"ef"));
    assert(res == true);
    res = runNFA(nfa, wordFromString(L"gh"));
    assert(res == true);

    // Test cases for strings that should not match
    res = runNFA(nfa, wordFromString(L"ab"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"cd"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"efgh"));
    assert(res == false);
    res = runNFA(nfa, wordFromString(L"ghab"));
    assert(res == false);

    print(L"Regex (ab|cd)*(ef|gh) NFA test successful\n\n");
}

int main_automata(void)
{
    (void)setlocale(LC_ALL, "");
    regexNFATest();

    return 0;
}
```
