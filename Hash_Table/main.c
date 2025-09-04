#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
int main(void) {
    HashTable* table = create_hash_table();
    if (!table) {
        return 1;
    }

    printf("=== Test Hash Table ===\n");


    printf("\n1. Inserari:\n");
    hash_insert(table, 1);
    hash_insert(table, 4);
    hash_insert(table, -1);
    hash_insert(table, 6);
    hash_insert(table, 8);
    hash_insert(table, 15);

    hash_print(table);


    printf("\n2. Test inserare duplicat:\n");
    hash_insert(table, 6);

    printf("\n3. Cautari:\n");
    node* result = hash_search(table, 6);
    if (result) {
        printf("Cheia 6 a fost gasita\n");
    } else {
        printf("Cheia 6 nu a fost gasita\n");
    }

    result = hash_search(table, 99);
    if (result) {
        printf("Cheia 99 a fost gasita\n");
    } else {
        printf("Cheia 99 nu a fost gasita\n");
    }


    printf("\n4. Stergeri:\n");
    hash_delete(table, 6);
    hash_delete(table, 99);


    hash_print(table);


    hash_destroy(table);

    return 0;
}