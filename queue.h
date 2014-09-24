#ifndef _QUEUE_H
#define _QUEUE_H

typedef char bool;
#define TURE 1;
#define FALSE 0;

typedef int queue_elem_t;

typedef struct queue_t{
    int front;
    int rear;
    queue_elem_t *elems;
    int capacity;
}queue_t;

void queue_init(queue_t *q, const int capacity);
void queue_destroy(queue_t *q);
bool queue_empty(const queue_t *q);
int queue_size(const queue_t *q);
void queue_push(queue_t *q, const queue_elem_t x);
void queue_pop(queue_t *q);
queue_elem_t queue_back(const queue_t *q);
queue_elem_t queue_front(const queue_t *q);

#include "queue.c"

#endif

