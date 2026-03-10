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
    perror("create_node");
    return NULL;
  }

  new_node->next = NULL;
  new_node->type_of_value = type_of_value;

  switch (type_of_value) {
  case 'i':
    int *copied_int = malloc(size);
    if (!copied_int) {
      free(new_node);
      perror("hard copying integer");
      return NULL;
    }
    *copied_int = *(int *)new_value;
    new_node->value = copied_int;
    break;
  case 'c':
    char *copied_char = malloc(size);
    if (!copied_char) {
      free(new_node);
      perror("hard copying character");
      return NULL;
    }
    *copied_char = *(char *)new_value;
    new_node->value = copied_char;
    break;
  case 's':
    char *copied_string = malloc(size);
    if (!copied_string) {
      free(new_node);
      perror("hard copying string");
      return NULL;
    }
    memcpy(copied_string, new_value, size);
    new_node->value = copied_string;
    break;
  default:
    fprintf(stderr, "create_node: unknown type '%c'\n", type_of_value);
    free(new_node);
    return NULL;
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
      printf("I actually don't know how you managed to get this here. "
             "Impressive...\n");
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

// Dynamic Array Functions
DynArr *create_dynarr() {
  DynArr *arr = malloc(sizeof(DynArr));
  if (!arr) {
    perror("create_dynarr");
    return NULL;
  }

  arr->count = 0;
  arr->capacity = 1;
  arr->data = malloc(sizeof(DynItem) * arr->capacity);
  if (!arr->data) {
    free(arr);
    perror("create_dynarr");
    return NULL;
  }

  return arr;
}

void dyn_add(DynArr *arr, char type, size_t size, void *value) {
  if (!arr) {
    fprintf(stderr, "dyn_add: array doesn't exist\n");
    return;
  }

  if (arr->count >= arr->capacity) {
    arr->capacity *= 2;
    DynItem *tmp = realloc(arr->data, sizeof(DynItem) * arr->capacity);
    if (!tmp) {
      perror("dyn_add");
      return;
    }

    arr->data = tmp;
  }

  DynItem item;
  item.type = type;
  switch (type) {
  case 'i':
    int *copied_int = malloc(size);
    if (!copied_int) {
      perror("hard copying integer");
      return;
    }
    *copied_int = *(int *)value;
    item.value = copied_int;
    break;
  case 'c':
    char *copied_char = malloc(size);
    if (!copied_char) {
      perror("hard copying character");
      return;
    }
    *copied_char = *(char *)value;
    item.value = copied_char;
    break;
  case 's':
    char *copied_string = malloc(size);
    if (!copied_string) {
      perror("hard copying string");
      return;
    }
    memcpy(copied_string, value, size);
    item.value = copied_string;
    break;
  default:
    fprintf(stderr, "dyn_add: unknown type: '%c'\n", type);
    return;
  }

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
      printf("%d. %c\n", i + 1, *(char *)arr->data[i].value);
      break;
    case 's':
      printf("%d. %s\n", i + 1, (char *)arr->data[i].value);
      break;
    default:
      printf("%d. BRO I DONT GET HOW YOU WOULD GET THIS TO HAPPEN. TELL ME: "
             "jacob@jsmitty.dev \n",
             i + 1);
    }
  }
}
