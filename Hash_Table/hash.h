#pragma once
#define TABLE_SIZE 7

typedef struct node {
    int key;
    struct node* next;
} node;

typedef struct {
    node* buckets[TABLE_SIZE];
    int size;
} HashTable;

int hash_function(int key);
HashTable* create_hash_table();
node* create_node(int key);
node* hash_search(const HashTable* table, int key);
int hash_insert(HashTable* table, int key);
void hash_print(const HashTable* table);
int hash_delete(HashTable* table, int key);
void hash_destroy(HashTable* table);
