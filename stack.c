#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

int is_empty(stack s)
{
    if(s->next == NULL)
        return TRUE;
    else
        return FALSE;
}


stack create_stack(void)
{
    stack s;
    s = (stack)malloc(sizeof(struct node));
    if(s == NULL) {
        printf("out of space!\n");
        return NULL;
    }
    s->data = 0;
    s->next = NULL;
    printf("stack is created!\n");
    return s;
}


void dispose_stack(stack s)
{
    
}

void make_empty(stack s)
{
    while(is_empty(s) == FALSE)
        pop(s);
}

stack push(stack s, int data)
{
    ptrtonode p;
    p = (ptrtonode)malloc(sizeof(struct node));
    if(p == NULL) {
        printf("out of space!\n");
        return NULL;
    }
    p->data = data;
    p->next = s->next;
    s->next = p;
    return s;
}

int pop(stack s)
{
    int data;
    ptrtonode p = s->next;
    if(is_empty(s) == TRUE) {
        printf("the stack is empty!\n");
        return 0;
    }
    else {
        data = p->data;
        s->next = p->next;
        free(p);
        return data;
    }
}

int top(stack s)
{
    int data;
    ptrtonode p = s->next;
    if(is_empty(s) == TRUE) {
        printf("this stack is empty!\n");
        return -1;
    }
    else {
        data = p->data;
        return data;
    }
}

