#include "lalr.h"

#include <stdarg.h>
#include <wchar.h>

typedef struct lalr_state
{
    unsigned int id;
    n_tuple transitions;
    n_tuple actions;
} lalr_state;

typedef struct lalr_parser
{
    n_tuple states;
    n_tuple stack_alphabet;
    n_tuple input_alphabet;
    n_tuple parsing_table;
    lalr_state start_state;
} lalr_parser;

// Create a new LALR(1) parser.
lalr LALR(unsigned int n, ...)
{
    va_list args;
    va_start(args, n);

    unsigned int num_states = va_arg(args, unsigned int);
    unsigned int num_stack_alphabet = va_arg(args, unsigned int);
    unsigned int num_input_alphabet = va_arg(args, unsigned int);
    unsigned int num_parsing_table = va_arg(args, unsigned int);
    unsigned int start_state_id = va_arg(args, unsigned int);

    n_tuple states = NTuple(num_states, NULL);
    n_tuple stack_alphabet = NTuple(num_stack_alphabet, NULL);
    n_tuple input_alphabet = NTuple(num_input_alphabet, NULL);
    n_tuple parsing_table = NTuple(num_parsing_table, NULL);

    for (unsigned int i = 0; i < num_states; i++)
    {
        lalr_state *state = malloc(sizeof(lalr_state));
        state->id = va_arg(args, unsigned int);
        state->transitions = va_arg(args, n_tuple);
        state->actions = va_arg(args, n_tuple);
        states = NTupleSet(states, i, state);
    }

    for (unsigned int i = 0; i < num_stack_alphabet; i++)
    {
        stack_alphabet = NTupleSet(stack_alphabet, i, va_arg(args, void *));
    }

    for (unsigned int i = 0; i < num_input_alphabet; i++)
    {
        input_alphabet = NTupleSet(input_alphabet, i, va_arg(args, void *));
    }

    for (unsigned int i = 0; i < num_parsing_table; i++)
    {
        parsing_table = NTupleSet(parsing_table, i, va_arg(args, void *));
    }

    va_end(args);

    lalr_parser *parser = malloc(sizeof(lalr_parser));
    parser->states = states;
    parser->stack_alphabet = stack_alphabet;
    parser->input_alphabet = input_alphabet;
    parser->parsing_table = parsing_table;
    parser->start_state = *(lalr_state *)NTupleGet(states, start_state_id);

    return (lalr)parser;
}

// Parse a string using the LALR(1) parser.
void parse(lalr parser, const wchar_t *str)
{
    lalr_parser *p = (lalr_parser *)parser;

    unsigned int str_length = wcslen(str);
    unsigned int stack_length = 1;
    void **stack = malloc(sizeof(void *) * stack_length);
    stack[0] = &p->start_state;

    unsigned int str_index = 0;
    unsigned int stack_index = 0;
    while (str_index < str_length)
    {
        lalr_state *state = (lalr_state *)stack[stack_index];
        void *symbol = (void *)str[str_index];
        unsigned int symbol_index = 0;
        for (unsigned int i = 0; i < getLength(p->input_alphabet); i++)
        {
            if (symbol == getObjectByIndex(p->input_alphabet, i))
            {
                symbol_index = i;
                break;
            }
        }

        unsigned int action_index = 0;
        for (unsigned int i = 0; i < getLength(state->actions); i++)
        {
            n_tuple action = (n_tuple)getObjectByIndex(state->actions, i);
            if (symbol_index == *(unsigned int *)getObjectByIndex(action, 0))
            {
                action_index = *(unsigned int *)getObjectByIndex(action, 1);
                break;
            }
        }

        if (action_index == 0)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }

        if (action_index == 1)
        {
            stack_index++;
            if (stack_index >= stack_length)
            {
                stack_length *= 2;
                stack = realloc(stack, sizeof(void *) * stack_length);
            }
            stack[stack_index] = symbol;
            str_index++;
        }
        else if (action_index == 2)
        {
            unsigned int num_pop = getLength((n_tuple)getObjectByIndex(state->actions, 0));
            stack_index -= num_pop;
            if (stack_index < 0)
            {
                printf("Error: stack underflow\n");
                return;
            }
            stack_index++;
            if (stack_index >= stack_length)
            {
                stack_length *= 2;
                stack = realloc(stack, sizeof(void *) * stack_length);
            }
            stack[stack_index] = getObjectByIndex((n_tuple)getObjectByIndex(state->actions, 0), 0);
        }
        else if (action_index == 3)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
        else if (action_index == 4)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
        else if (action_index == 5)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
        else if (action_index == 6)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
        else if (action_index == 7)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
        else if (action_index == 8)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
        else if (action_index == 9)
        {
            printf("Error: no action for symbol %lc in state %u\n", (wchar_t)symbol, state->id);
            return;
        }
    }

    printf("Success!\n");
}

// Free the memory allocated for the LALR(1) parser.
void freeLALR(lalr parser)
{
    lalr_parser *p = (lalr_parser *)parser;
    for (unsigned int i = 0; i < getLength(p->states); i++)
    {
        free(getObjectByIndex(p->states, i));
    }
    free(p->states);
    free(p->stack_alphabet);
    free(p->input_alphabet);
    free(p->parsing_table);
    free(p);
}
