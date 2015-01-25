#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
int main()
{
    BiTreePtr pRoot = NULL;
    BiTreePtr p = NULL;
    printf("create a binary tree:\n");
    CreateBiTree(pRoot);
    int n;
    for(n = 1; n < 10; n++)
        pRoot = insert_node(n, pRoot);

    printf("pre travel result is :");
    PreTravelBiTree(pRoot);
    putchar('\n');
    p = find_max(pRoot);
    printf("max number is %d\n", p->data);
    p = find_min(pRoot);
    printf("min number is %d\n", p->data);
    p = find_element(7, pRoot);
    printf("the number we are finding is %d\n", p->data);
    delete_node(3, pRoot);
    PreTravelBiTree(pRoot);
    putchar('\n');
    return 0;
}
*/

int main()
{
    int length = 8;
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    BiTreePtr pRoot =  Construct(preorder, inorder, length);
    PostTravelBiTree(pRoot);    
}
