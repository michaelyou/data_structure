#include <stdio.h>
#include <stdlib.h>
#include "sort.c"

int main(int argc, char **argv) {
    int a[1000] = {1,3,2,8,9,45,74,12,68,10,91,54,7,2,8,9};
    merge_sort(a, 16);
    //int a[40] = {1,3,2,3,2,2,2,2,2,2,2,3,2,2,3,4};
    //quick_sort(a, 0, 15);
    //heap_sort(a, 16);
    int i;
    for(i = 0; i < 16; i++)
        printf("%d ", a[i]);

    printf("\n");
}
