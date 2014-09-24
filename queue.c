#include <stdlib.h>
#include <string.h>
#include "queue.h"


void queue_init(queue_t *q, const int capacity)
{
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q = (queue_elem_t*)malloc(capacity * (sizeof(queue_elem_t));
}

void queue_destroy(queue_t *q) {
    q->front = 0;
    q->rear = 0;
    q->capacity = 0;
    free(q->elems);
    q->elems = NULL;
}

bool queue_empty(const queue_t *q)
{
    return q->front == q->rear;
}

int queue_size(const queue_t *q)
{
    return (q->rear - q->front + q->capacity) % q->capacity;
}

void queue_push(queue_t *q, const queue_elem_t x)
{
    if(q->rear+1) % q->capacity == q->front) {
        queue_elem_t *tmp = (queue_elem_t *)malloc(q->capacity * 2 * sizeof(queue_elem_t*));
        
    }
}