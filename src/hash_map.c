#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { TYPE_INT, TYPE_CHAR, TYPE_STRING } ValueType;

typedef struct HashNode {
  char *key;
  ValueType type;
  void *value;
  struct HashNode *next;
} HashNode;

typedef struct {
  HashNode **buckets;
  int numBuckets;
} HashMap;

int hashKey(int numBuckets, char *key) {
  int total = 0;
  for (; *key; key++) {
    total += *key;
  }

  return total % numBuckets;
}

HashMap *create_hashmap(int numBuckets) {
  HashMap *newHash = malloc(sizeof(HashMap));
  newHash->numBuckets = numBuckets;
  newHash->buckets = malloc(sizeof(HashMap *) * numBuckets);
  for (int i = 0; i < numBuckets; i++) {
    newHash->buckets[i] = NULL;
  }

  return newHash;
}

HashNode *makeNode(char *key, ValueType type, void *value) {
  HashNode *newNode = malloc(sizeof(HashNode));
  if (!newNode) {
    return NULL;
  }
  // Decided to use the if statement this instead of switch for seperate scopes
  if (type == TYPE_INT) {
    newNode->value = (int *)value;
  } else if (type == TYPE_CHAR) {
    newNode->value = (char *)value;
  } else if (type == TYPE_STRING) {
    newNode->value = (char *)value;
  } else {
    perror("Unknown type\n");
    free(newNode);
    return NULL;
  }

  newNode->type = type;
  newNode->key = malloc(strlen(key) + 1);
  if (!newNode->key) {
    free(newNode);
    fprintf(stderr, "failed to malloc for key\n");
    return NULL;
  }
  memcpy(newNode->key, key, strlen(key) + 1);

  newNode->next = NULL;

  return newNode;
}

void addHash(HashMap *hash, char *key, ValueType type, void *value) {
  int index = hashKey(hash->numBuckets, key);
  HashNode *newNode = makeNode(key, type, value);

  if (!hash->buckets[index]) {
    hash->buckets[index] = newNode;
    return;
  }

  HashNode *current = hash->buckets[index];
  while (current->next) {
    current = current->next;
  }
  current->next = newNode;
}

void print_hashmap(HashMap *map) {
  int num = map->numBuckets;
  for (int i = 0; i < num; i++) {
    HashNode *cur = map->buckets[i];
    while (cur) {
      printf("%s: ", cur->key);
      if (cur->type == TYPE_INT) {
        printf("%d\n", *(int *)cur->value);
      } else if (cur->type == TYPE_CHAR) {
        printf("%c\n", *(char *)cur->value);
      } else if (cur->type == TYPE_STRING) {
        printf("%s\n", (char *)cur->value);
      } else {
        fprintf(stderr, "HOW DO WE GET HERE??\n");
        return;
      }

      cur = cur->next;
    }
  }
}

void free_hashmap(HashMap **map) {
  if (map == NULL || *map == NULL) {
    return;
  }

  for (int i = 0; i < (*map)->numBuckets; i++) {
    HashNode *cur = (*map)->buckets[i];
    while (cur) {
      HashNode *next = cur->next;
      free(cur->key);
      free(cur);
      cur = next;
    }
  }
  free((*map)->buckets);
  free(*map);
  *map = NULL;
}

int main() {
  HashMap *map = create_hashmap(10);
  char jacob_age = 'j';
  int youssef_age = 10;
  char *dans_age = "thirty one";

  addHash(map, "Youssef", TYPE_INT, &youssef_age);
  addHash(map, "Jacob", TYPE_CHAR, &jacob_age);
  addHash(map, "Dan", TYPE_STRING, dans_age);
  print_hashmap(map);

  return 0;
}
