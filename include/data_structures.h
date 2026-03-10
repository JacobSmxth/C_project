#ifndef DATA_STRUCTURES_H

#define DATA_STRUCTURES_H

#include <stddef.h>

typedef struct LlNode LlNode;

LlNode *create_list();

LlNode *create_node(char type_of_value, size_t size, void *new_value);

void list_add(LlNode **list, LlNode *new_node);

void print_list(LlNode *list);

void free_list(LlNode *list);

#endif
