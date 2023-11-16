#include "n_tuple.h"
#include "nondeterministic_finite_automaton.h"
#include "set.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void singleLetterNFATest(void)
{
    nondeterministic_finite_automaton nfa = createLetterNFA(letter_y);
    printNFA(nfa);
    bool res = runNFA(nfa, letter_y);
    assert(res == true);
    print(L"Singe letter NFA test successful\n\n");
}

void concatinatedNFATest(void)
{
    nondeterministic_finite_automaton nfa_left = createLetterNFA(letter_x);
    nondeterministic_finite_automaton nfa_right = createLetterNFA(letter_y);
    nondeterministic_finite_automaton nfa = createConcatinationNFA(nfa_left, nfa_right);
    printNFA(nfa);
    bool res = runNFA(nfa, Word(2, letter_x, letter_y));
    assert(res == true);

    nfa = createConcatinationNFA(nfa, nfa_right);
    printNFA(nfa);
    res = runNFA(nfa, Word(3, letter_x, letter_y, letter_y));
    assert(res == true);

    print(L"Concatinated NFA test successful\n\n");
}

void unionNFATest(void)
{
    nondeterministic_finite_automaton nfa_left = createLetterNFA(letter_x);
    nondeterministic_finite_automaton nfa_right = createLetterNFA(letter_y);
    nondeterministic_finite_automaton nfa = createUnionNFA(nfa_left, nfa_right);
    printNFA(nfa);
    bool res = runNFA(nfa, letter_x);
    assert(res == true);
    res = runNFA(nfa, letter_y);
    assert(res == true);
    print(L"Union NFA test successful\n\n");
}

void iterationNFATest(void)
{
    nondeterministic_finite_automaton nfa_iter = createLetterNFA(letter_x);
    nondeterministic_finite_automaton nfa = createIterationNFA(nfa_iter);
    printNFA(nfa);
    bool res = runNFA(nfa, letter_x);
    assert(res == true);
    res = runNFA(nfa, Word(2, letter_x, letter_x));
    assert(res == true);
    res = runNFA(nfa, Word(3, letter_x, letter_x, letter_x));
    assert(res == true);
    print(L"Iteration NFA test successful\n\n");
}

void regexWithoutSubexpressionNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFAWithoutSubexpression(Word(2, letter_x, letter_y));
    printNFA(nfa);
    bool res = runNFA(nfa, Word(2, letter_x, letter_y));
    assert(res == true);
    res = runNFA(nfa, Word(3, letter_x, letter_x, letter_z));
    assert(res == false);
    res = runNFA(nfa, letter_x);
    assert(res == false);
    res = runNFA(nfa, letter_y);
    assert(res == false);
    res = runNFA(nfa, Word(2, letter_x, letter_x));
    assert(res == false);
    res = runNFA(nfa, NULL);
    assert(res == false);
    res = runNFA(nfa, Word(3, letter_x, letter_y, letter_z));
    assert(res == false);
    print(L"Regex without subexpression NFA test successful\n\n");
}

void regexWithoutSubexpressionUnionNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFAWithoutSubexpression(Word(3, letter_x, letter_bar, letter_y));
    printNFA(nfa);
    bool res = runNFA(nfa, letter_x);
    assert(res == true);
    res = runNFA(nfa, letter_y);
    assert(res == true);
    res = runNFA(nfa, letter_z);
    assert(res == false);
    res = runNFA(nfa, Word(2, letter_x, letter_y));
    assert(res == false);
    print(L"Regex without subexpression union NFA test successful\n\n");
}

void regexWithoutSubexpressionUnionAndIterationNFATest(void)
{
    nondeterministic_finite_automaton nfa = createRegexNFAWithoutSubexpression(Word(4, letter_x, letter_bar, letter_y, letter_star));
    printNFA(nfa);
    bool res = runNFA(nfa, letter_x);
    assert(res == true);
    res = runNFA(nfa, NULL);
    assert(res == true);
    res = runNFA(nfa, letter_y);
    assert(res == true);
    res = runNFA(nfa, Word(2, letter_y, letter_y));
    assert(res == true);
    res = runNFA(nfa, Word(3, letter_y, letter_y, letter_y));
    assert(res == true);
    res = runNFA(nfa, Word(2, letter_y, letter_z));
    assert(res == false);
    res = runNFA(nfa, Word(2, letter_x, letter_y));
    assert(res == false);
    print(L"Regex without subexpression union and iteration NFA test successful\n\n");
}

int main_automata(void)
{
    (void)setlocale(LC_ALL, "");
    singleLetterNFATest();
    concatinatedNFATest();
    unionNFATest();
    iterationNFATest();
    regexWithoutSubexpressionNFATest();
    regexWithoutSubexpressionUnionNFATest();
    regexWithoutSubexpressionUnionAndIterationNFATest();

    return 0;
}
