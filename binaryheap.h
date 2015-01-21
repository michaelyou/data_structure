/*
 *数组实现，左儿子:left_son = parent * 2
            右儿子:right_son = parent * 2 + 1
*/
#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <stdlib.h>
#include <stdio.h>

#define bool int
#define true 1
#define false 0

/*采用数组的方式实现完全二叉堆*/
typedef struct binary_heap
{
    int *parray;   //需要动态扩展，所以使用动态数组
    int current_size;   //当前存在的节点
    int capacity;  //堆的实际容量
}binaryheap_t, *binaryheap_handle_t;



bool init_binaryheap(binaryheap_handle_t heap, int capacity);
bool alloc_binaryheap(binaryheap_handle_t *heap, int capacity);
void delete_binaryheap(binaryheap_handle_t heap);
void free_binaryheap(binaryheap_handle_t *heap);

bool insert(binaryheap_handle_t heap, int value);
int deletemin(binaryheap_handle_t heap);
bool is_empty(binaryheap_handle_t heap);
static void presort_binaryheap(binaryheap_handle_t heap, int hole);



#endif
