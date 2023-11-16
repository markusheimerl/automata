#include "hash_table.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

static const unsigned int default_table_size = 100;

struct hash_table_
{
    void **table;
    unsigned int table_size;
    unsigned int full_size;
    unsigned int traversal_index;
};

// Function to calculate hash
static unsigned int hash(void *data, unsigned int table_size)
{
    /*
    golden_ratio = (1 + sqrt(5)) / 2 = 1.6180339887498948482045868343656...
    int_max_frac = 2^32 / golden_ratio = 2654435769.4972302964775847707926...
    (int)int_max_frac = 2654435769 = 0x9E3779B9
    */

    unsigned int golden_ratio = 0x9E3779B9;
    unsigned long int value = (unsigned long int)data * golden_ratio;
    value = value >> 32;
    return (unsigned int)value % table_size;
}

static hash_table HashTableWithSize(unsigned int table_size)
{
    hash_table newTable = (hash_table)malloc(sizeof(struct hash_table_));
    newTable->table = (void **)calloc(table_size, sizeof(void *));
    newTable->table_size = table_size;
    newTable->full_size = 0;
    newTable->traversal_index = 0;
    return newTable;
}

// Create a new hash table
hash_table HashTable()
{
    return HashTableWithSize(default_table_size);
}

static void resize(hash_table ht)
{
    unsigned int old_table_size = ht->table_size;
    unsigned int number_of_previous_resizes = old_table_size / default_table_size;
    unsigned long int new_table_size_long_int = (unsigned long int)old_table_size + (unsigned long int)default_table_size * number_of_previous_resizes;
    assert(new_table_size_long_int <= UINT_MAX);
    hash_table temp_ht = HashTableWithSize((unsigned int)new_table_size_long_int);

    for (unsigned int i = 0; i < old_table_size; i++)
    {
        insert(temp_ht, traverse(ht));
    }
    void **temp = ht->table;
    ht->table = temp_ht->table;
    ht->table_size = temp_ht->table_size;
    ht->full_size = temp_ht->full_size;
    ht->traversal_index = temp_ht->traversal_index;

    temp_ht->table = temp;

    freeHashTable(temp_ht);
}

// Insert data into hash table
void insert(hash_table ht, void *data)
{
    unsigned int idx = hash(data, ht->table_size);
    void *temp = ht->table[idx];

    for (unsigned int i = 0; temp != NULL; i++)
    {
        if (i == ht->table_size)
        {
            resize(ht);
            insert(ht, data);
            return;
        }
        idx = (idx + 1) % ht->table_size;
        temp = ht->table[idx];
    }

    ht->table[idx] = data;
    ht->full_size++;
}

// Find data in hash table
bool find(hash_table ht, void *data)
{
    unsigned int idx = hash(data, ht->table_size);
    void *temp = ht->table[idx];

    for (unsigned int i = 0; temp != data; i++)
    {
        if (i == ht->table_size)
        {
            return false;
        }
        idx = (idx + 1) % ht->table_size;
        temp = ht->table[idx];
    }

    return true;
}

// Delete a data from hash table
bool take_out(hash_table ht, void *data)
{
    unsigned int idx = hash(data, ht->table_size);
    void *temp = ht->table[idx];

    for (unsigned int i = 0; temp != data; i++)
    {
        if (i == ht->table_size)
        {
            return false; // data not in table
        }
        idx = (idx + 1) % ht->table_size;
        temp = ht->table[idx];
    }
    ht->table[idx] = NULL;
    ht->full_size -= 1;
    return true;
}

// Returns next data pointer or null if the table is empty
void *traverse(hash_table ht)
{
    void *temp = ht->table[ht->traversal_index];

    for (unsigned int i = 0; temp == NULL; i++)
    {
        if (i == ht->table_size)
        {
            return NULL; // table empty, nothing to traverse
        }
        ht->traversal_index = (ht->traversal_index + 1) % ht->table_size;
        temp = ht->table[ht->traversal_index];
    }

    ht->traversal_index = (ht->traversal_index + 1) % ht->table_size;
    return temp;
}

// Get the number of data entries in the table
unsigned int getSize(hash_table ht)
{
    return ht->full_size;
}

// Free hash table
void freeHashTable(hash_table ht)
{
    free(ht->table);
    free(ht);
}
