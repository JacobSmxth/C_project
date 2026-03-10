#include "data_structures.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_int(const char *s) {
  if (*s == '-' || *s == '+')
    s++;

  if (*s == '\0')
    return false;

  while (*s) {
    if (!isdigit(*s)) {
      return false;
    }
    s++;
  }
  return true;
}

bool is_char(const char *s) { return (strlen(s) == 1 && isalpha(*s)); }

bool is_string(const char *s) {
  if (strlen(s) <= 1) {
    return false;
  }

  while (*s) {
    if (isalpha(*s)) {
      return true;
    }
    s++;
  }

  return false;
}

int main() {
  LlNode *the_values = create_list();
  int i = 0;
  while (i < 5) {
    printf("What value would you like to add?: ");
    char input[100];

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char type;
    if (is_string(input)) {
      type = 's';
      LlNode *new_node = create_node(type, strlen(input) + 1, input);
      list_add(&the_values, new_node);
    } else if (is_int(input)) {
      type = 'i';
      int parsed = atoi(input);
      LlNode *new_node = create_node(type, sizeof(int), &parsed);
      list_add(&the_values, new_node);
    } else if (is_char(input)) {
      type = 'c';
      char parsed = input[0];
      LlNode *new_node = create_node(type, sizeof(char), &parsed);
      list_add(&the_values, new_node);
    } else {
      fprintf(stderr, "'%s' produced an error and was not picked up\n", input);
      exit(EXIT_FAILURE);
    }

    i++;
  }
  print_list(the_values);
  free_list(the_values);
  return 0;
}
