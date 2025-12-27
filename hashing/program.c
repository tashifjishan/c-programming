#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10


struct Node {
    char* key;
    char* value;
    struct Node* next;
};
struct Node *hashTable[TABLE_SIZE];

int hashFunction(const char* key) {
    int hash = 0;

    while (*key) {
        hash = (hash * 31) + (*key);
        key++;
    }
    return hash % TABLE_SIZE;
}

    
void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}


void put(const char* key, const char* value) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    
    /* Check if key already exists */
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            free(temp->value);
            temp->value = strdup(value);
            return;
        }
        temp = temp->next;
    }

    /* Create new struct struct Node */
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}


char* get(const char* key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }

    return NULL;  /* key not found */
}


int main() {
    init();

    
    put("name", "Alice");
    put("age", "20");
    put("city", "Delhi");
    put("country", "India");

    /* Update value */
    put("name", "harry");

    printf(get("name"));
    printf("\n");
    printf(get("age"));
    printf("\n");
    printf(get("city"));
    printf("\n");
    printf(get("country"));
    return 0;
}


/*
char* copy = strdup("hello");

is equivalent to:

char* copy = malloc(strlen("hello") + 1);
strcpy(copy, "hello");


*/