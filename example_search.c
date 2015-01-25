#include <stdio.h>
#include "search.c"

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b = BinSearch(a, 10, 8);
    printf("%d\n", b);
}
