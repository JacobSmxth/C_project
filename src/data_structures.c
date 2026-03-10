#include "data_structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic Array Structure
typedef struct DynItem {
  void *value;
  char type;
} DynItem;

typedef struct DynArr {
  int count;
  int capacity;
  DynItem *data;
} DynArr;

// Linked List Structure
typedef struct LlNode {
  struct LlNode *next;
  char type_of_value;
  void *value;
} LlNode;

// Linked List Functions
LlNode *create_list() { return NULL; }

LlNode *create_node(char type_of_value, size_t size, void *new_value) {
  LlNode *new_node = malloc(sizeof(LlNode));
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

void list_add(LlNode **list, LlNode *new_node) {
  if (!*list) {
    *list = new_node;
    return;
  }

  LlNode *current = *list;
  while (current->next) {
    current = current->next;
  }
  current->next = new_node;
}

void print_list(LlNode *list) {
  LlNode *current = list;

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
      printf("Corrupt LlNode in list...\n");
    }
    current = current->next;
  }
}

void free_list(LlNode *list) {
  LlNode *current = list;
  while (current) {
    LlNode *next = current->next;
    free(current->value);
    free(current);
    current = next;
  }
}

// Struct layout
//
// typedef struct DynArr {
//   int count;
//   int capacity;
//   void **data;
// } DynArr;
//

// Dynamic Array Functions
DynArr *create_dynarr() {

  DynArr *arr = malloc(sizeof(DynArr));

  if (!arr) {
    exit(EXIT_FAILURE);
  }

  arr->count = 0;
  arr->capacity = 1;
  arr->data = malloc(sizeof(DynItem) * arr->capacity);
  if (!arr->data) {
    exit(EXIT_FAILURE);
  }

  return arr;
}

void dyn_add(DynArr *arr, char type, size_t size, void *value) {
  if (!arr) {
    exit(EXIT_FAILURE);
  }

  if (arr->count >= arr->capacity) {
    arr->capacity *= 2;
    DynItem *tmp = realloc(arr->data, sizeof(DynItem) * arr->capacity);
    if (!tmp) {
      exit(EXIT_FAILURE);
    }

    arr->data = tmp;
  }

  DynItem item;
  item.type = type;
  switch (type) {
  case 'i':
    int *copied_int = malloc(size);
    if (!copied_int) {
      exit(EXIT_FAILURE);
    }
    copied_int = (int *)value;
    item.value = copied_int;
    break;
  case 'c':
    char *copied_char = malloc(size);
    if (!copied_char) {
      exit(EXIT_FAILURE);
    }
    copied_char = (char *)value;
    item.value = copied_char;
    break;
  case 's':
    char *copied_string = malloc(size);
    if (!copied_string) {
      exit(EXIT_FAILURE);
    }
    memcpy(copied_string, value, size);
    item.value = copied_string;
    break;
  default:
    printf("ERROR\n");
  }
  item.value = value;

  arr->data[arr->count++] = item;
}

void free_dyn(DynArr *arr) {
  for (int i = 0; i < arr->count; i++) {
    free(arr->data[i].value);
  }
  free(arr->data);
  free(arr);
}

void print_dyn(DynArr *arr) {
  for (int i = 0; i < arr->count; i++) {
    switch (arr->data[i].type) {
    case 'i':
      printf("%d. %d\n", i + 1, *(int *)arr->data[i].value);
      break;
    case 'c':
      printf("%d. %d\n", i + 1, *(char *)arr->data[i].value);
      break;
    case 's':
      printf("%d. %s\n", i + 1, (char *)arr->data[i].value);
      break;
    default:
      printf("%d. ERROR WITH TYPE\n", i + 1);
    }
  }
}
