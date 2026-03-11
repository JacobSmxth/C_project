#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum { TYPE_INT, TYPE_CHAR, TYPE_STRING } ValueType;

typedef struct HashNode {
  char *key;
  int value;
  struct HashNode *next;
} HashNode;

typedef struct {
  HashNode **buckets;
  int numBuckets;
} HashMap;

int hashKey(int num, char *key) {
  int total = 0;
  for (; *key; key++) {
    total += *key;
  }

  return total % num;
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

void addHash(HashMap *hash, char *key, int value) {
  int index = hashKey(hash->numBuckets, key);

  HashNode *newNode = malloc(sizeof(HashNode));
  if (!newNode)
    return;

  newNode->key = malloc(strlen(key) + 1);
  if (!newNode->key) {
    free(newNode);
    return;
  }

  memcpy(newNode->key, key, strlen(key) + 1);
  newNode->value = value;
  newNode->next = NULL;

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
      printf("%s: %d\n", cur->key, cur->value);
      cur = cur->next;
    }
  }
}

int main() {
  HashMap *map = create_hashmap(10);
  addHash(map, "Youssef", 10);
  addHash(map, "Jacob", 20);
  addHash(map, "Dan", 31);
  print_hashmap(map);

  return 0;
}
