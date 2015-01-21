/*
 *����ʵ�֣������:left_son = parent * 2
            �Ҷ���:right_son = parent * 2 + 1
*/
#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <stdlib.h>
#include <stdio.h>

#define bool int
#define true 1
#define false 0

/*��������ķ�ʽʵ����ȫ�����*/
typedef struct binary_heap
{
    int *parray;   //��Ҫ��̬��չ������ʹ�ö�̬����
    int current_size;   //��ǰ���ڵĽڵ�
    int capacity;  //�ѵ�ʵ������
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
