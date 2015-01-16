#include <stdio.h>
#include <stddef.h> /*for NULL*/

typedef int elem_t;

typedef struct tbt_node_t {
    int ltag;
    int rtag;
    struct tbt_node_t *lchild;
    struct tbt_node_t *rchild;
    elem_t data;
}tbt_node_t;

static void in_thread(tbt_node_t *p, tbt_node_t **pre);
static tbt_node_t *first(tbt_node_t *p);
static tbt_node_t *next(const tbt_node_t *p);

void  create_in_thread(tbt_node_t *root)
{
    tbt_node_t *pre = NULL;
    if(root != NULL) {
        in_thread(root, &pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

void in_order(tbt_node_t *root, int(*visit)(


