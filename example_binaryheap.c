#include "binaryheap.h"
#include <stdio.h>
#include <time.h>
#include <assert.h>

void print_binaryheap(binaryheap_handle_t heap)
{
    int i = 0;

    assert(heap != NULL && heap->parray != NULL);

    for(i = 1; i <= heap->current_size; ++ i)
    {
        if(i %6)
                printf("%d\t",heap->parray[i]);
        else
                printf("\n%d\t",heap->parray[i]);
    }
    printf("\n");
}


int main()
{
    int i = 0;
    int value = 0;

    srand((int)time(0));
    printf("********Test Binaryheap**************\n");

    binaryheap_t bheap;
    binaryheap_handle_t pheap = NULL;

    printf("init and alloc test:\n");
    if(init_binaryheap(&bheap, 10))
    {
        printf("init_BinaryHeap() successed!\n");
    }
    if (alloc_binaryheap(&pheap, 15));
    {
        printf("alloc_BInaryHeap() successed!\n");
    }

    printf("***insert test*****\n");
    for(; i < 10; ++ i)
    {
        if(!insert(&bheap,5 * i - rand()%20))
        {
            printf("i = %d:insert failed !!\n",i);
        }
    }
    for(i = 0; i < 15; ++ i)
    {
        if(!insert(pheap,i * 8 - rand()%20))
        {
            printf("i = %d:insert failed!!\n",i);
        }
    }

    print_binaryheap(&bheap);
    print_binaryheap(pheap);

    printf("****deleteMin test****\n");
    for(i = 0; i < 5; ++ i)
    {
        value = deletemin(&bheap);
        printf("bheap deleted:%d\n",value);
        value = deletemin(pheap);
        printf("pheap deleted:%d\n",value);
    }
    print_binaryheap(&bheap);
    print_binaryheap(pheap);

    printf("deleteMin test successed\n");

    printf("****delete and free test:*******\n");
    delete_binaryheap(&bheap);

    printf("Is the bheap empty ? %s\n",
                    is_empty(&bheap)?"Yes":"No");

    free_binaryheap(&pheap);

    printf("*********Test successed!***********\n");
    pheap = NULL;
    return 0;
}

