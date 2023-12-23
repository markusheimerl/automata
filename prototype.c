#include "nondeterministic_finite_automaton.h"
#include <assert.h>
#include <locale.h>

void setTest(void)
{
    set s = Set();
    s = addToSet(s, &letter_b);
    s = addToSet(s, &letter_c);
    s = addToSet(s, &letter_b);
    s = addToSet(s, &letter_d);

    assert(getCardinality(s) == 3);
    assert(isElementOf(s, &letter_b));
    assert(isElementOf(s, &letter_c));
    assert(isElementOf(s, &letter_d));
    for (unsigned int i = 0; i < 47; i++)
    {
        void *p = drawFromSet(s);
        assert(p == &letter_b || p == &letter_c || p == &letter_d);
    }
}

void orderedPairTest(void)
{
    ordered_pair p = OrderedPair(&letter_a, &letter_b);
    assert(getFirst(p) == &letter_a);
    assert(getSecond(p) == &letter_b);

    p = OrderedPair(&letter_c, &letter_c);
    assert(getFirst(p) == &letter_c);
    assert(getSecond(p) == &letter_c);
}

void regexNFATest(void)
{
    // Simpler regex: (ab|cd)*(ef|gh)
    nondeterministic_finite_automaton nfa = regexNFA(wordFromString(L"(ab|cd)*(ef|gh)"));
    printNFA(nfa);

    // Test cases for strings that should match
    bool res = runNFA(nfa, wordFromString(L"abef"));
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
    // setTest();
    // orderedPairTest();

    return 0;
}
