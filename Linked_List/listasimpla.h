#pragma once

typedef struct SLL_NODE{
    int key;
    struct SLL_NODE* next;
}SLL_NODE;

typedef struct {
    SLL_NODE *first;
    SLL_NODE *last;
}SL_LIST;

SL_LIST *create_single_linked_list();
void sll_print_list(const SL_LIST *list);
SLL_NODE *create_sll_node(int value);
void sll_insert_first(SL_LIST *list, int given_key);
void sll_insert_last(SL_LIST *list, int given_key);
SLL_NODE *sll_search(const SL_LIST *list, int search_key);
void sll_insert_after_key(SL_LIST *list, int search_key, int value);
void sll_delete_first(SL_LIST *list);
void sll_delete_last(SL_LIST *list);
void sll_delete_key(SL_LIST *list, int search_key);
void destroy_single_linked_list(SL_LIST *sl_list);
void sll_reverse(SL_LIST *list);
