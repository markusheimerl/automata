#include "set.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 100

enum
{
    default_size_of_the_universe = 100000
};

struct set_
{
    unsigned int size;
    unsigned int index;
    void **data;
};

set universe_of_discourse[default_size_of_the_universe] = {NULL};

static set Set_(unsigned int size)
{
    set s = malloc(sizeof(struct set_));
    s->size = size;
    s->index = 0;
    s->data = calloc(s->size, sizeof(void *));
    return s;
}

set Set()
{
    if (universe_of_discourse[0] == NULL)
    {
        universe_of_discourse[0] = Set_(DEFAULT_SIZE);
        return universe_of_discourse[0];
    }
    else
    {
        return universe_of_discourse[0];
    }
}

bool isObjectASet(void *p)
{
    assert(p != NULL);

    for (unsigned int i = 0; i < default_size_of_the_universe; i++)
    {
        if (universe_of_discourse[i] == p)
        {
            return true;
        }
    }

    return false;
}

long int find(set s, void *object)
{
    for (unsigned int i = 0; i < s->size; i++)
    {
        if (s->data[i] == object)
        {
            return i;
        }
    }

    return -1;
}

static void *draw(set s)
{
    unsigned int loops = 0;
    while (s->data[s->index] == NULL && loops < s->size)
    {
        s->index = (s->index + 1) % s->size;
        loops++;
    }
    return s->data[s->index];
}

void *drawFromSet(set s)
{
    assert(isObjectASet(s));
    return draw(s);
}

static set checkForIdenticalSetInUniverse(set s)
{
    for (unsigned int i = 0; i < default_size_of_the_universe; i++)
    {
        set u_s = universe_of_discourse[i];

        if (u_s == NULL)
        {
            universe_of_discourse[i] = s;
            return s;
        }
        else if (u_s->size == s->size)
        {
            bool identical = true;

            for (unsigned int j = 0; j < u_s->size; j++)
            {
                if (find(u_s, draw(s)) == -1)
                {
                    identical = false;
                    break;
                }
            }
            if (identical)
            {
                free(s->data);
                free(s);
                return u_s;
            }
        }
    }

    assert(false && "Universe is full.");
}

set addToSet(set s, void *object)
{
    assert(isObjectASet(s));

    if (find(s, object) != -1)
        return s;

    unsigned int size = 0;
    if (find(s, NULL) == -1)
    {
        size = s->size * ((s->size % DEFAULT_SIZE) * 2);
    }
    else
    {
        size = s->size;
    }

    set new_set = Set_(size);
    memcpy(new_set->data, s->data, s->size * sizeof(void *));
    new_set->data[find(new_set, NULL)] = object;

    return checkForIdenticalSetInUniverse(new_set);
}

bool isElementOf(set s, void *object)
{
    assert(isObjectASet(s));
    return (find(s, object) != -1);
}

set removeFromSet(set s, void *object)
{
    assert(isObjectASet(s));

    if (find(s, object) == -1)
        return s;

    set new_set = Set_(s->size);
    memcpy(new_set->data, s->data, s->size * sizeof(void *));
    new_set->data[find(new_set, object)] = NULL;

    return checkForIdenticalSetInUniverse(new_set);
}

unsigned int getCardinality(set s)
{
    assert(isObjectASet(s));
    return (unsigned int)find(s, NULL);
}

set unionSet(set s, set t)
{
    assert(isObjectASet(s));
    assert(isObjectASet(t));

    set new_set = Set_(s->size + t->size);
    for (unsigned int i = 0; i < s->size; i++)
    {
        memcpy(new_set->data, s->data, s->size * sizeof(void *));
    }
    for (unsigned int i = 0; i < t->size; i++)
    {
        if (find(new_set, t->data[i]) == -1)
        {
            new_set->data[find(new_set, NULL)] = t->data[i];
        }
    }

    return checkForIdenticalSetInUniverse(new_set);
}