#include<stdio.h>
#include"sort.c"

int main(int argc, char **argv) {
    int a[1000] = {1,2};
    insert_sort(a, 35222);
    int i;
    for(i = 0; i < 35222; i++)
        printf("%d ", a[i]);
}
