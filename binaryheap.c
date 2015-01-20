#include "binaryheap.h"
#include <assert.h>

bool is_empty(binaryheap_handle_t heap)
{
    assert(heap != NULL);
    return heap->current_size == 0;
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

void delete_binaryheap(binaryheap_handle_t heap)
{
    assert(heap != NULL && heap->parray != NULL);
    heap->capacity = 0;
    heap->current_size = 0;

    free(heap->parray);
    heap->parray = NULL;
}

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

bool alloc_binaryheap(binaryheap_handle_t *heap, int capacity)
{
    int *parray = NULL;

    if(*heap != NULL)
        return false;

    *heap = (int *)calloc(1, sizeof(binaryheap_t));
    if(*heap == NULL)
        return false;

    parray = (int *)calloc(capacity + 1, sizeof(int));
    if(parray == NULL)
        return false;

    (*heap)->parray = parray;
    (*heap)->capacity = 0;
    (*heap)->current_size = 0;

    return true;
}

bool insert(binaryheap_handle_t heap, int value)
{
    int index = 0;

    if(heap == NULL || heap->parray == NULL)
        return false;

    index = ++heap->current_size;

    while(index > 1 && value < heap->parray[index/2])
    {
        heap->parray[index] = heap->parray[index/2];
        index /= 2;
    }

    heap->parray[index] = value;

    return true;
}

static void presort_binaryheap(binaryheap_handle_t heap, int hole)
{
    int child = hole * 2;
    int tmp = 0;

    assert(heap != NULL && heap->parray != NULL);
    tmp = heap->parray[hole];

    for(; hole * 2 <= heap->current_size; hole = child) {
        child = hole * 2;
        if((child != heap->current_size) 
            && (heap->parray[child + 1] < heap->parray[child]))
            child++;
        if(heap->parray[child] < tmp)
        {
            heap->parray[hole] = heap->parray[child];
        }
    }
    heap->parray[hole] = tmp;
}

int deletemin(binaryheap_handle_t heap)
{
    int ret = 0;
    int index = 0;

    assert(!is_empty(heap));
    ret = heap->parray[1];

    heap->parray[1] = heap->parray[heap->current_size--];
    presort_binaryheap(heap, 1);

    return ret;
}