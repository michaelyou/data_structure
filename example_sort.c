#include <stdio.h>
#include <stdlib.h>
#include "sort.c"

int main(int argc, char **argv) {
    int a[1000] = {1,3,2,8,9,45,74,12,68,10,91,54,7};
    //merge_sort(a, 0, 12);
    select_sort(a, 13);
    int i;
    for(i = 0; i < 13; i++)
        printf("%d ", a[i]);

    printf("\n");
}
