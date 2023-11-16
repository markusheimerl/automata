#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

/**
 * @brief Typedef for the hash table data structure.
 */
typedef struct hash_table_ *hash_table;

/**
 * @brief Creates and returns a new hash table with a default size.
 *
 * @return A pointer to the newly created hash table.
 */
hash_table HashTable(void);

/**
 * @brief Inserts a data pointer into the hash table.
 *
 * This function inserts the given data into the table.
 * If the table needs resizing, it will be automatically resized.
 *
 * @param ht A pointer to the hash table.
 * @param data The data pointer to insert.
 */
void insert(hash_table ht, void *data);

/**
 * @brief Searches for a data pointer in the hash table.
 *
 * Searches the table for a given data. If found, the function returns true.
 *
 * @param ht A pointer to the hash table.
 * @param data The data pointer to search for.
 * @return true if the data is found, false otherwise.
 */
bool find(hash_table ht, void *data);

/**
 * @brief Removes a data pointer from the hash table.
 *
 * Deletes a given data from the hash table.
 *
 * @param ht A pointer to the hash table.
 * @param data The data pointer to remove.
 * @return true if the data is successfully removed, false otherwise.
 */
bool take_out(hash_table ht, void *data);

/**
 * @brief Traverses the hash table and returns the next data pointer.
 *
 * This function returns the next available data pointer in the hash table.
 * Returns NULL if the table is empty.
 *
 * @param ht A pointer to the hash table.
 * @return A pointer to the data or NULL if the table is empty.
 */
void *traverse(hash_table ht);

/**
 * @brief Returns the number of data entries in the hash table.
 *
 * @param ht A pointer to the hash table.
 * @return The number of data entries in the hash table.
 */
unsigned int getSize(hash_table ht);

/**
 * @brief Frees the allocated memory for the hash table.
 *
 * This function deallocates the memory allocated for the hash table and its internal arrays.
 * It does not try to free the data pointers stored in the table.
 *
 * @param ht A pointer to the hash table.
 */
void freeHashTable(hash_table ht);

#endif // HASH_TABLE_H
