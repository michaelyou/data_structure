#ifndef _STACK_H
#define _STACK_H

typedef struct node {
    int data;
    struct node *next;
}*ptrtonode;

typedef ptrtonode stack;

int is_empty(stack s);
void make_empty(stack s);
stack create_stack(void);
void dispose_stack(stack s);
stack push(stack s, int data);
int pop(stack s);
int top(stack s);

#include "stack.c"
#endif
