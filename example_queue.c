#include "queue.h"
#include <stdio.h>

#define CAP 10

int main()
{
    struct queue_t p;
    queue_t *q = &p;
    int x = 0;
    int i = 0;
    int capacity = CAP;
    
    queue_init(q, capacity);
    if(queue_empty(q) == 1)
        printf("the queue is empty\n");
    for(i = 0; i < 9; i++) {
        queue_push(q, i);
    }
    if(queue_empty(q) == 1)
        printf("the queue is empty\n");
    for(i = 0; i < 9; i++) {
        printf("%d ", queue_front(q));
        queue_pop(q);
    }
}
