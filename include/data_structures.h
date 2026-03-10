#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stddef.h>

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

typedef struct DynItem DynItem;

typedef struct DynArr DynArr;

/**
 * @brief Create an empty list
 *
 *
 * @return Technically a pointer to the head of the list, but it is just NULL.
 *
 */
LlNode *create_list();

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

DynArr *create_dynarr();

void dyn_add(DynArr *arr, char type, size_t size, void *value);

void print_dyn(DynArr *arr);

void free_dyn(DynArr *arr);

#endif
