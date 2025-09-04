#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasimpla.h"

int main() {
    SL_LIST *list = NULL;
    SLL_NODE *node = NULL;
    int search_key = 0;

    list = create_single_linked_list();
    if (!list) {
        printf("Nu s-a putut crea lista\n");
        return 1;
    }

    sll_insert_first(list, 4);
    sll_insert_first(list, 1);
    sll_insert_last(list, 3);

    printf("Lista originala: ");
    sll_print_list(list);
    printf("\n");

    sll_reverse(list);
    printf("Lista inversata: ");
    sll_print_list(list);
    printf("\n");

    search_key = 2;
    node = sll_search(list, search_key);
    if (node == NULL) {
        printf("Nodul cu cheia %d NU a fost gasit!\n", search_key);
    } else {
        printf("Nodul cu cheia %d a fost gasit la adresa %p\n", search_key, node);
    }

    search_key = 3;
    node = sll_search(list, search_key);
    if (node == NULL) {
        printf("Nodul cu cheia %d NU a fost gasit!\n", search_key);
    } else {
        printf("Nodul cu cheia %d a fost gasit la adresa %p\n", search_key, node);
    }

    sll_insert_after_key(list, 4, 22);
    sll_insert_after_key(list, 3, 25);

    printf("Dupa inserari: ");
    sll_print_list(list);
    printf("\n");

    sll_delete_first(list);
    sll_delete_last(list);
    sll_delete_key(list, 22);
    sll_delete_key(list, 8);

    printf("Dupa stergeri: ");
    sll_print_list(list);
    printf("\n");

    destroy_single_linked_list(list);
    list = NULL;

    return 0;
}