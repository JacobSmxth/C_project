#include "data_structures.h"
#include <string.h>

int main() {
  Node *list = create_list();
  char my_name[] = "Jacob Smith";
  char gf_name[] = "Cecilia Ippoliti";
  list_add(&list, create_node('s', strlen(my_name) + 1, &my_name));
  list_add(&list, create_node('s', strlen(gf_name) + 1, &gf_name));
  print_list(list);
}
