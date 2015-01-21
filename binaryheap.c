#include "binaryheap.h"
#include <assert.h>

bool is_empty(binaryheap_handle_t heap)
{
    assert(heap != NULL);
    return heap->current_size == 0;
}


bool alloc_binaryheap(binaryheap_handle_t *heap, int capacity)
{
    int *parray = NULL;

    if(*heap != NULL)
        return false;

    *heap = (int *)calloc(1, sizeof(binaryheap_t));
    if(*heap == NULL)
        return false;
    //位置0作为标记，加1是为了让数组从1开始计
    parray = (int *)calloc(capacity + 1, sizeof(int));
    if(parray == NULL)
        return false;

    (*heap)->parray = parray;
    (*heap)->capacity = 0;
    (*heap)->current_size = 0;

    return true;
}


bool init_binaryheap(binaryheap_handle_t heap, int capacity)
{
    int *parray = NULL;

    if(heap == NULL)
        return false;
    parray = (int *)calloc(capacity+1, sizeof(int));
    if(parray == NULL)
        return false;

    heap->parray = parray;
    heap->capacity = capacity;
    heap->current_size = 0;

    return true;
}

//清空堆中的数据，并释放分配的内存，但不删除二叉堆
void delete_binaryheap(binaryheap_handle_t heap)
{
    assert(heap != NULL && heap->parray != NULL);
    heap->capacity = 0;
    heap->current_size = 0;

    free(heap->parray);
    heap->parray = NULL;
}

//删除堆，释放内存
void free_binaryheap(binaryheap_handle_t * heap)
{
    assert(*heap != NULL);

    (*heap)->capacity = 0;
    (*heap)->current_size = 0;

    free((*heap)->parray);
    (*heap)->parray = NULL;

    free(*heap);
    *heap = NULL;
}


/**************************************************
 * 采用上虑法实现数据的插入操作
 * 上虑法的实现方式比较简单，首先创建一个空节点
 * 然后将需要插入的值与当前空穴的父结点进行比较
 * 如果大于父结点，直接插入空穴中
 * 如果小于父结点的值，则将父结点的值下拉到空穴中
 * 之前父结点的位置就是空穴，接着与上层比较
 * 直到找到父结点大于当前插入值的情况
 **************************************************/
bool insert(binaryheap_handle_t heap, int value)
{
    int index = 0;

    if(heap == NULL || heap->parray == NULL)
        return false;
    /*得到一个新的空穴下标*/
    index = ++heap->current_size;
    /*条件是不是第一个下标和插入值比对应父结点小*/
    while(index > 1 && value < heap->parray[index/2])
    {
        /*将父结点保存到当前结点处*/
        heap->parray[index] = heap->parray[index/2];
        /*得到父结点的空穴位置*/
        index /= 2;
    }
    /*将插入的值保存到剩余的空穴中*/
    heap->parray[index] = value;

    return true;
}

/***********************************************************
 * 下虑法实现数据的重排序操作
 * 实现的方式，将子结点的两个儿子进行比较，将小的提升
 * 需要注意的是如何让判断节点是否一定存在右儿子
 * 实现的方式主要是利用了二叉堆的特性:
 * 2*pare = L_child
 * 2*pare + 1 = R_child; 
 ***********************************************************/
static void presort_binaryheap(binaryheap_handle_t heap, int hole)
{
    int child = hole * 2;
    int tmp = 0;

    assert(heap != NULL && heap->parray != NULL);
    tmp = heap->parray[hole];

    /*hold * 2 <= heap->currentSize 判断了当前结点是否为最低层*/
    for(; hole * 2 <= heap->current_size; hole = child) {
        child = hole * 2;
        /*******************************
         *这句代码解决是否存在右结点的问题
         *并确定了那个子结点提升的问题
         *******************************/
        if((child != heap->current_size) 
            && (heap->parray[child + 1] < heap->parray[child]))
            child++;
            
        if(heap->parray[child] < tmp)
        {
            /*将子结点提升为父结点*/
            heap->parray[hole] = heap->parray[child];
        }
    }
    /*到达了最低的层，也就是树叶*/
    heap->parray[hole] = tmp;
}

/*实现数据的下虑法实现数据的删除操作*/
int deletemin(binaryheap_handle_t heap)
{
    int ret = 0;
    int index = 0;

    assert(!is_empty(heap));
    ret = heap->parray[1];
    /*将最后需要释放内存空间的值保存到第一个内存空间中*/
    heap->parray[1] = heap->parray[heap->current_size--];
    /*从表头开始将新的二叉树进行重新排序*/
    presort_binaryheap(heap, 1);

    return ret;
}