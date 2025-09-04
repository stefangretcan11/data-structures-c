#pragma once

typedef struct {
    int *array;
    int capacity;
    int head;
    int tail;
    int size;
}QUEUE;

QUEUE *create_queue(int capacity);
void destroy_queue(QUEUE *queue);
void queue_enqueue(QUEUE *queue, int key);
void print_queue_contents(const QUEUE *queue);
int queue_dequeue(QUEUE *queue);