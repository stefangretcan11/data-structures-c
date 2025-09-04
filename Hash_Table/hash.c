#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int hash_function(int key) {
    return ((2 * key) % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

HashTable* create_hash_table() {
    HashTable* table = calloc(1, sizeof(HashTable));
    if (!table) {
        printf("Eroare: Nu se poate aloca memoria pentru hash table\n");
        return NULL;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    table->size = 0;
    return table;
}

node* create_node(int key) {
    node* new_node = calloc(1, sizeof(node));
    if (!new_node) {
        printf("Eroare: Nu se poate aloca memoria pentru nod\n");
        return NULL;
    }
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

node* hash_search(const HashTable* table, int key) {
    if (!table) return NULL;

    int pos = hash_function(key);
    node* current = table->buckets[pos];

    while (current) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}
int hash_insert(HashTable* table, int key) {
    if (!table) return 0;

    if (hash_search(table, key) != NULL) {
        printf("Cheia %d deja exista in hash table\n", key);
        return 0;
    }

    int pos = hash_function(key);
    node* new_node = create_node(key);
    if (!new_node) return 0;
    new_node->next = table->buckets[pos];
    table->buckets[pos] = new_node;
    table->size++;

    return 1;
}

void hash_print(const HashTable* table) {
    if (!table) {
        printf("Hash table este NULL\n");
        return;
    }

    printf("\n=== Hash Table (marime: %d) ===\n", table->size);
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        node* current = table->buckets[i];
        if (!current) {
            printf("(gol)");
        } else {
            while (current) {
                printf("%d", current->key);
                if (current->next) printf(" -> ");
                current = current->next;
            }
        }
        printf("\n");
    }
    printf("================================\n");
}


int hash_delete(HashTable* table, int key) {
    if (!table) return 0;

    int pos = hash_function(key);
    node* current = table->buckets[pos];
    node* prev = NULL;

    while (current) {
        if (current->key == key) {
            if (prev == NULL) {

                table->buckets[pos] = current->next;
            } else {

                prev->next = current->next;
            }

            free(current);
            table->size--;
            printf("Cheia %d a fost stearsa\n", key);
            return 1;
        }
        prev = current;
        current = current->next;
    }

    printf("Cheia %d nu a fost gasita pentru stergere\n", key);
    return 0;
}

void hash_destroy(HashTable* table) {
    if (!table) return;

    for (int i = 0; i < TABLE_SIZE; i++) {
        node* current = table->buckets[i];
        while (current) {
            node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(table);
    printf("Hash table a fost distrus\n");
}