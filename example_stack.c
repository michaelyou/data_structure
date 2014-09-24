#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    stack s;
    int n;
    s = create_stack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    while(is_empty(s) == FALSE) {
        n = top(s);
        printf("%4d", n);
        n = pop(s);
        printf("%4d", n);
    }

    return 0;
}
