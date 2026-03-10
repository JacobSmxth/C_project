#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stddef.h>

/* =============
 * Linked List
 * ============= */

/**
 * @struct LlNode
 * @brief Opaque node type for this generic linked list
 *
 *
 * The LlNode structure is a single element in this linked list. The internal
 * structure is hidden to the user.
 *
 */
typedef struct LlNode LlNode;

/**
 * @brief Create an empty list
 *
 *
 * @return Technically a pointer to the head of the list, but it is just NULL.
 *
 */
LlNode *create_list(void);

/**
 * @brief Create a new node for linked list
 *
 * @param type_of_value Type identifier ('i': int, 'c': char, 's': string)
 * @param size Size of the value in bytes
 * @param new_value Pointer to the value to store
 *
 * @return Pointer to this new node
 */
LlNode *create_node(char type_of_value, size_t size, void *new_value);

/**
 * @brief Add a node to the end of the list.
 *
 * @param list Pointer to the list head pointer
 * @param new_node Node to append
 */
void list_add(LlNode **list, LlNode *new_node);

/**
 * @brief Print the contents of the list.
 *
 * Traverses the list and prints each stored value based on its type.
 *
 * @param list Head of the list
 */
void print_list(LlNode *list);

/**
 * @brief Free all memory used by the list
 *
 * Frees both the nodes and their stored values
 *
 * @param list Head of the list
 */
void free_list(LlNode *list);

/* =============
 * Dyn Arr
 * ============= */

/**
 * @brief Opaque dynamic array
 *
 * This is the heart and soul of the dynamic array
 */
typedef struct DynArr DynArr;

/**
 * @brief Create a generic Dynamic Array
 *
 * @return Pointer to list, that starts with a count of 0, capacity of 1, and
 * storage for one DynItem
 */
DynArr *create_dynarr(void);

/**
 * @brief Add to the Dynamic array specified
 *
 * @param arr This is the array we are adding to.
 * @param type The type of item we are adding ('i': int, 'c': char, 's': string)
 * @param size The size of the item in bytes
 * @param value The Value of the item
 */
void dyn_add(DynArr *arr, char type, size_t size, void *value);

/**
 * @brief Traverses the array based on the count and prints each item's value
 *
 * @param arr The array we are printing
 */
void print_dyn(DynArr *arr);

/**
 * @brief Traverses the array using count and frees each items value, then the
 * data, then the array
 *
 // * @param arr The array we are freeing
 */
void free_dyn(DynArr *arr);

#endif
