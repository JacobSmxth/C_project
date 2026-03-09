#include "data_structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  struct Node *next;
  char type_of_value;
  void *value;
} Node;

Node *create_list() { return NULL; }

Node *create_node(char type_of_value, size_t size, void *new_value) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    exit(EXIT_FAILURE);
  }

  new_node->next = NULL;
  new_node->type_of_value = type_of_value;

  switch (type_of_value) {
  case 'i':
    int *copied_int = malloc(size);
    if (!copied_int) {
      free(new_node);
      exit(EXIT_FAILURE);
    }
    *copied_int = *(int *)new_value;
    new_node->value = copied_int;
    break;
  case 'c':
    char *copied_char = malloc(size);
    if (!copied_char) {
      free(new_node);
      exit(EXIT_FAILURE);
    }
    *copied_char = *(char *)new_value;
    new_node->value = copied_char;
    break;
  case 's':
    char *copied_string = malloc(size);
    if (!copied_string) {
      free(new_node);
      exit(EXIT_FAILURE);
    }
    memcpy(copied_string, new_value, size);
    new_node->value = copied_string;
    break;
  default:
    free(new_node);
    exit(EXIT_FAILURE);
  }

  return new_node;
}

void list_add(Node **list, Node *new_node) {
  if (!*list) {
    *list = new_node;
    return;
  }

  Node *current = *list;
  while (current->next) {
    current = current->next;
  }
  current->next = new_node;
}

void print_list(Node *list) {
  Node *current = list;

  while (current) {
    switch (current->type_of_value) {
    case 'i':
      printf("%d\n", *(int *)current->value);
      break;
    case 'c':
      printf("%c\n", *(char *)current->value);
      break;
    case 's':
      printf("%s\n", (char *)current->value);
      break;
    default:
      printf("Corrupt Node in list...\n");
    }
    current = current->next;
  }
}

void free_list(Node *list) {
  Node *current = list;
  while (current) {
    Node *next = current->next;
    free(current->value);
    free(current);
    current = next;
  }
}
