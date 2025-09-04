#include <stdio.h>
#include "list.h"


int main() {
    QUEUE *queue = NULL;

    queue = create_queue(7);
    if (!queue) {
        printf("Failed to create queue\n");
        return 1;
    }


    queue_enqueue(queue, 1);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 5);
    queue_enqueue(queue, 2);

    print_queue_contents(queue); // 1 3 5 2
    printf("\n");

    queue_dequeue(queue);
    queue_dequeue(queue);

    print_queue_contents(queue); // 5 2
    printf("\n");

    queue_enqueue(queue, 4);
    queue_enqueue(queue, 9);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 6);

    print_queue_contents(queue); // 5 2 4 9 2 6
    printf("\n");

    queue_dequeue(queue);

    print_queue_contents(queue); // 2 4 9 2 6
    printf("\n");

    queue_enqueue(queue, 3);
    queue_enqueue(queue, 7);

    print_queue_contents(queue); // 2 4 9 2 6 3 7
    printf("\n");

    queue_enqueue(queue, 9);  // overflow

    destroy_queue(queue);
    queue = NULL;

    return 0;
}
