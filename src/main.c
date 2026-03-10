#include "data_structures.h"
#include <string.h>

int main() {
  LlNode *list = create_list();
  char my_name[] = "Jacob Smith";
  int my_age = 20;
  char gf_name[] = "Cecilia Ippoliti";
  list_add(&list, create_node('s', strlen(my_name) + 1, &my_name));
  list_add(&list, create_node('s', strlen(gf_name) + 1, &gf_name));
  print_list(list);

  DynArr *dynArr = create_dynarr();

  dyn_add(dynArr, 's', strlen(my_name) + 1, &my_name);
  dyn_add(dynArr, 'i', sizeof(my_age), &my_age);
  print_dyn(dynArr);
}
