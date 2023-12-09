#include "set.h"
#include <assert.h>
#include <stddef.h>

enum
{
    default_size_of_the_universe = 100000
};

set universe_of_discourse[default_size_of_the_universe] = {NULL};

static bool isSetInUniverse(set s)
{
    assert(s != NULL);

    for (unsigned int i = 0; i < default_size_of_the_universe; i++)
    {
        if (universe_of_discourse[i] == s)
        {
            return true;
        }
    }

    return false;
}

bool isObjectASet(void *p)
{
    return isSetInUniverse(p);
}

set Set()
{
    if (universe_of_discourse[0] == NULL)
    {
        universe_of_discourse[0] = HashTable();
        return universe_of_discourse[0];
    }
    else
    {
        return universe_of_discourse[0];
    }
}

set addToSet(set s, void *object)
{
    assert(isSetInUniverse(s));

    if (find(s, object))
        return s;

    set new_set = HashTable();
    for (unsigned int i = 0; i < getSize(s); i++)
    {
        insert(new_set, traverse(s));
    }
    insert(new_set, object);

    for (unsigned int i = 0; i < default_size_of_the_universe; i++)
    {
        set u_s = universe_of_discourse[i];

        if (u_s == NULL)
        {
            universe_of_discourse[i] = new_set;
            return new_set;
        }
        else if (getSize(u_s) == getSize(new_set))
        {
            bool identical = true;

            for (unsigned int j = 0; j < getSize(u_s); j++)
            {
                if (!find(u_s, traverse(new_set)))
                {
                    identical = false;
                    break;
                }
            }
            if (identical)
            {
                freeHashTable(new_set);
                return u_s;
            }
        }
    }

    assert(false && "Universe is full.");
}

bool isElementOf(set s, void *object)
{
    assert(isSetInUniverse(s));

    return find(s, object);
}

set removeFromSet(set s, void *object)
{
    assert(isSetInUniverse(s));

    if (!find(s, object))
        return s;

    set new_set = HashTable();
    for (unsigned int i = 0; i < getSize(s); i++)
    {
        void *o = traverse(s);
        if (o != object)
            insert(new_set, o);
    }

    for (unsigned int i = 0; i < default_size_of_the_universe; i++)
    {
        set u_s = universe_of_discourse[i];

        if (u_s == NULL)
        {
            universe_of_discourse[i] = new_set;
            return new_set;
        }
        else if (getSize(u_s) == getSize(new_set))
        {
            bool identical = true;

            for (unsigned int j = 0; j < getSize(u_s); j++)
            {
                if (!find(u_s, traverse(new_set)))
                {
                    identical = false;
                    break;
                }
            }
            if (identical)
            {
                freeHashTable(new_set);
                return u_s;
            }
        }
    }

    assert(false && "Universe is full.");
}

void *drawFromSet(set s)
{
    assert(isSetInUniverse(s));

    return traverse(s);
}

unsigned int getCardinality(set s)
{
    assert(isSetInUniverse(s));

    return getSize(s);
}

set unionSet(set s, set t)
{
    assert(isSetInUniverse(s));
    assert(isSetInUniverse(t));

    set new_set = HashTable();
    for (unsigned int i = 0; i < getSize(s); i++)
    {
        insert(new_set, traverse(s));
    }
    for (unsigned int i = 0; i < getSize(t); i++)
    {
        insert(new_set, traverse(t));
    }

    for (unsigned int i = 0; i < default_size_of_the_universe; i++)
    {
        set u_s = universe_of_discourse[i];

        if (u_s == NULL)
        {
            universe_of_discourse[i] = new_set;
            return new_set;
        }
        else if (getSize(u_s) == getSize(new_set))
        {
            bool identical = true;

            for (unsigned int j = 0; j < getSize(u_s); j++)
            {
                if (!find(u_s, traverse(new_set)))
                {
                    identical = false;
                    break;
                }
            }
            if (identical)
            {
                freeHashTable(new_set);
                return u_s;
            }
        }
    }

    assert(false && "Universe is full.");
}