#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

STACK *create_stack() {
    STACK *stack = calloc(1, sizeof(STACK));
    if (!stack) {
        printf("Eroare: Nu se poate aloca memoria pentru stack\n");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int is_empty(STACK *stack) {
    return (stack == NULL || stack->top == NULL);
}

void stack_push(STACK *stack, int key) {
    if (!stack) return;

    STACK_NODE *new_node = calloc(1, sizeof(STACK_NODE));
    if (!new_node) {
        printf("Eroare: Nu se poate aloca memoria pentru nod\n");
        return;
    }

    new_node->key = key;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    printf("Push: %d (marime stack: %d)\n", key, stack->size);
}

int stack_pop(STACK *stack) {
    if (is_empty(stack)) {
        printf("Eroare: Stack gol - nu se poate face pop\n");
        return -1;
    }

    int result = stack->top->key;
    STACK_NODE *temp = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    free(temp);

    printf("Pop: %d (marime stack: %d)\n", result, stack->size);
    return result;
}

int stack_peek(STACK *stack) {
    if (is_empty(stack)) {
        printf("Eroare: Stack gol - nu se poate face peek\n");
        return -1;
    }
    return stack->top->key;
}

void print_stack(STACK *stack) {
    if (is_empty(stack)) {
        printf("Stack gol\n");
        return;
    }

    printf("Stack (top->bottom): ");
    STACK_NODE *current = stack->top;
    while (current) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("(marime: %d)\n", stack->size);
}

void destroy_stack(STACK *stack) {
    if (!stack) return;

    printf("Distrugere stack...\n");
    while (!is_empty(stack)) {
        stack_pop(stack);
    }
    free(stack);
    printf("Stack distrus cu succes\n");
}
