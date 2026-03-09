#ifndef DATA_STRUCTURES_H

#define DATA_STRUCTURES_H

#include <stddef.h>

typedef struct Node Node;

Node *create_list();

Node *create_node(char type_of_value, size_t size, void *new_value);

void list_add(Node **list, Node *new_node);

void print_list(Node *list);

void free_list(Node *list);

#endif
