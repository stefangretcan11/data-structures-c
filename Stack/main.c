#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(void) {
    printf("=== Test Stack Implementation ===\n\n");

    STACK *stack = create_stack();
    if (!stack) {
        return 1;
    }

    printf("1. Test push:\n");
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);
    stack_push(stack, 40);
    print_stack(stack);
    printf("\n");

    printf("2. Test peek:\n");
    printf("Peek: %d\n", stack_peek(stack));
    print_stack(stack);
    printf("\n");

    printf("3. Test pop:\n");
    stack_pop(stack);
    stack_pop(stack);
    print_stack(stack);
    printf("\n");

    printf("4. Push dupa pop:\n");
    stack_push(stack, 50);
    stack_push(stack, 60);
    print_stack(stack);
    printf("\n");

    printf("5. Pop toate elementele:\n");
    while (!is_empty(stack)) {
        stack_pop(stack);
    }
    print_stack(stack);
    printf("\n");

    printf("6. Test operatii pe stack gol:\n");
    stack_pop(stack);
    stack_peek(stack);
    printf("\n");

    printf("7. Push pe stack gol:\n");
    stack_push(stack, 100);
    print_stack(stack);
    printf("\n");

    destroy_stack(stack);

    return 0;
}