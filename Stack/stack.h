#pragma once

typedef struct _STACK_NODE {
    int key;
    struct _STACK_NODE *next;
} STACK_NODE;

typedef struct {
    STACK_NODE *top;
    int size;
} STACK;

STACK *create_stack();
int is_empty(STACK *stack);
void stack_push(STACK *stack, int key);
int stack_pop(STACK *stack);
int stack_peek(STACK *stack);
void print_stack(STACK *stack);
void destroy_stack(STACK *stack);