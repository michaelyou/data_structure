#include <stdio.h>
#include "list.h"

void printlist(node *l);

#define max 400000
int main()
{
    node *l = NULL;
    l = create_list(l ,0);
    int n;
    for(n = 1; n < max; n++) {
        insert_list(l, n, 5);
    }

    printlist(l);
}

void printlist(node *l)
{
    if(l != NULL) {
        printf("%d", l->next->data);
        printlist(l->next->next);
    }
}
