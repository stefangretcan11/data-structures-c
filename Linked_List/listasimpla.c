
#include <stdio.h>
#include <stdlib.h>
#include "listasimpla.h"

SL_LIST *create_single_linked_list() {
    SL_LIST* L = calloc(1, sizeof(SL_LIST));
    if (!L) {
        printf("Eroare: Nu s-a putut aloca memoria pentru lista\n");
        return NULL;
    }
    L->first = NULL;
    L->last = NULL;
    return L;
}

void sll_print_list(const SL_LIST *list) {
    if (!list || list->first == NULL) {
        printf("Lista e goala");
        return;
    }

    SLL_NODE *p = list->first;
    while (p != NULL) {
        printf("%d ", p->key);
        p = p->next;
    }
}

SLL_NODE *create_sll_node(int value) {
    SLL_NODE *p = calloc(1, sizeof(SLL_NODE));
    if (!p) {
        printf("Eroare: Nu s-a putut aloca memoria pentru nod\n");
        return NULL;
    }
    p->key = value;
    p->next = NULL;
    return p;
}

void sll_insert_first(SL_LIST *list, int given_key) {
    if (!list) return;

    SLL_NODE *q = create_sll_node(given_key);
    if (!q) return;

    if (list->first == NULL) {
        list->first = q;
        list->last = q;
    } else {
        q->next = list->first;
        list->first = q;
    }
}
void sll_insert_last(SL_LIST *list, int given_key) {
    if (!list) return;

    SLL_NODE *p = create_sll_node(given_key);
    if (!p) return;

    if (list->first == NULL) {
        list->first = p;
        list->last = p;
        return;
    }

    list->last->next = p;
    list->last = p;
}

SLL_NODE *sll_search(const SL_LIST *list, int search_key) {
    if (!list || !list->first) return NULL;

    SLL_NODE *q = list->first;
    while (q != NULL) {
        if (q->key == search_key) {
            return q;
        }
        q = q->next;
    }
    return NULL;
}

void sll_insert_after_key(SL_LIST *list, int search_key, int value) {
    if (!list) return;

    SLL_NODE *q = sll_search(list, search_key);
    if (!q) {
        printf("Cheia %d nu a fost gasita, nu se poate insera dupa\n", search_key);
        return;
    }

    SLL_NODE *p = create_sll_node(value);
    if (!p) return;

    p->next = q->next;
    q->next = p;

    if (q == list->last) {
        list->last = p;
    }
}

void sll_delete_first(SL_LIST *list) {
    if (!list || list->first == NULL) return;

    SLL_NODE *q = list->first;
    list->first = q->next;

    if (list->first == NULL) {
        list->last = NULL;
    }

    free(q);
}

void sll_delete_last(SL_LIST *list) {
    if (!list || list->first == NULL) return;

    if (list->first == list->last) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    }

    SLL_NODE *q = list->first;
    while (q->next != list->last) {
        q = q->next;
    }

    free(list->last);
    q->next = NULL;
    list->last = q;
}

void sll_delete_key(SL_LIST *list, int search_key) {
    if (!list || !list->first) return;

    if (list->first->key == search_key) {
        sll_delete_first(list);
        return;
    }

    SLL_NODE *prev = list->first;
    SLL_NODE *curr = prev->next;

    while (curr != NULL) {
        if (curr->key == search_key) {
            prev->next = curr->next;

            if (curr == list->last) {
                list->last = prev;
            }

            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Cheia %d nu a fost gasita pentru stergere\n", search_key);
}

void destroy_single_linked_list(SL_LIST *sl_list) {
    if (!sl_list) return;

    while (sl_list->first != NULL) {
        sll_delete_first(sl_list);
    }
    free(sl_list);
}

void sll_reverse(SL_LIST *list) {
    if (!list || !list->first) return;

    SLL_NODE *prev = NULL;
    SLL_NODE *curr = list->first;
    SLL_NODE *next = NULL;

    list->last = list->first;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->first = prev;
}
