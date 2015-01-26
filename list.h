#ifndef _LIST_H
#define _LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
}*node;

void create_list(node &head, int num);
void print_list(node head);
void add_list(node head, int n);
int delete_list(node head, int n);
int length(node head);
int insert_list(node head, int a, int e);
int update_list(node head, int a, int e);
node destroy_list(node head);
int search_list(node head, int e);
node reverse_list(node head);
node sort_list(node head);
void printnodes(node head, int n);
void printlots(node head_l, node head_p);
node find_node_by_position(node head,int n);
void swap_node(node beforep, node head);
node list_intersect(node head_l, node head_p);
node list_union(node head_l, node head_p);

#include "list.c"
#endif