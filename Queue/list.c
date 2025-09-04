#include <stdio.h>
#include <stdlib.h>
#include "list.h"


QUEUE *create_queue(int capacity) {
    QUEUE *queue = calloc(1,sizeof(QUEUE));
    queue->array = calloc(capacity,sizeof(int));
    queue->capacity=capacity;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void destroy_queue(QUEUE *queue) {
    free(queue->array);
    free(queue);
}

void queue_enqueue(QUEUE *queue, int key) {
    if(queue->capacity==queue->size)
    {
        printf("Coada e plina");
        return;
    }
    queue->array[queue->tail] = key;
    queue->tail++;
    queue->tail %= queue->capacity;
    queue->size++;
}

int queue_dequeue(QUEUE *queue) {
    if(queue->size == 0) return 0;
    int r = queue->array[queue->head];
    queue->head++;
    queue->head %= queue->capacity;  // Fixed: need to wrap head around too
    queue->size--;
    return r;
}

void print_queue_contents(const QUEUE *queue) {
    if (!queue) {
        printf("Error: Queue is NULL\n");
        return;
    }

    if (queue->size == 0) {
        printf("Queue is empty");
        return;
    }

    int current = queue->head;
    for (int i = 0; i < queue->size; i++) {
        printf("%d", queue->array[current]);
        if (i < queue->size - 1) {
            printf(" ");
        }
        current = (current + 1) % queue->capacity;
    }
}