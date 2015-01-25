#include <stdio.h>
#include <limits.h>

int main()
{
    int a = 2000000000;
    int b = 2000000000;
    printf("%d\n", INT_MAX);
    if(a > INT_MAX - b)
        printf("out\n");
    printf("%d", (a + b));
}
