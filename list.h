#ifndef _LIST_H
#define _LIST_H

typedef struct node
{
    int data;
    struct node *next;
}*Node_t;

void create_list(Node_t &head, int num);
void print_list(Node_t head);
void add_list(Node_t head, int n);
Node_t delete_list(Node_t head, int n);
int length(Node_t head);
int insert_list(Node_t head, int a, int e);
int update_list(Node_t head, int a, int e);
void destroy_list(Node_t head);
int search_list(Node_t head, int e);
Node_t reverse_list(Node_t head);
Node_t sort_list(Node_t head);
void printnodes(Node_t head, int n);
void printlots(Node_t head_l, Node_t head_p);
Node_t find_node_by_position(Node_t head,int n);
void swap_node(Node_t beforep, Node_t head);
Node_t list_intersect(Node_t head_l, Node_t head_p);
Node_t list_union(Node_t head_l, Node_t head_p);

#include "list.c"
#endif