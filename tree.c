#include "tree.h"


void CreateBiTree(BiTreePtr &pRoot)
{
    int a;
    scanf("%d", &a);
    if(a == 0)
        pRoot = NULL;
    else {
        pRoot = (node *)malloc(sizeof(node));
        pRoot->data = a;
        CreateBiTree(pRoot->plChild);
        CreateBiTree(pRoot->prChild);
    } 
}



/*
void CreateBiTree(BiTreePtr *pRoot)
{
    int a;
    scanf("%d", &a);
    if(a == 0) {
        (*pRoot) = NULL;
    }
    else {
        *pRoot = (BiTreePtr)malloc(sizeof(BiTreePtr));
        (*pRoot)->data = a;
        CreateBiTree(&((*pRoot)->plChild));
        CreateBiTree(&((*pRoot)->prChild));
    }
}
  */
  
void PreTravelBiTree(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return;
    else {
        printf("%d", pRoot->data);
        PreTravelBiTree(pRoot->plChild);
        PreTravelBiTree(pRoot->prChild);
    }
}

void MidTravelBiTree(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return;
    else {
        MidTravelBiTree(pRoot->plChild);
        printf("%d", pRoot->data);
        MidTravelBiTree(pRoot->prChild);
    }
}

void PostTravelBiTree(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return;
    else {
        PostTravelBiTree(pRoot->plChild);
        PostTravelBiTree(pRoot->prChild);
        printf("%d", pRoot->data);
    }
}

int FindDepth(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return 0;
    else {
        int a = FindDepth(pRoot->plChild);
        int b = FindDepth(pRoot->prChild);
        return(a>b?a:b)+1;
    }
}

void FreeBiTree(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return;
    FreeBiTree(pRoot->plChild);
    FreeBiTree(pRoot->prChild);
    free(pRoot);
}

BiTreePtr find_element(int a, BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return NULL;
    if(a < pRoot->data)
        return find_element(a, pRoot->plChild);
    else if(a > pRoot->data)
        return find_element(a, pRoot->prChild);
    else
        return pRoot;
}

BiTreePtr find_min(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return NULL;
    else if(pRoot->plChild== NULL)
        return pRoot;
    else
        return find_min(pRoot->plChild);
}
/*
BiTreePtr find_min(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return NULL;
    while(pRoot->plChild != NULL)
        pRoot = pRoot->plChild;

    return pRoot;
}
 */
BiTreePtr find_max(BiTreePtr pRoot)
{
    if(pRoot == NULL)
        return NULL;
    else if(pRoot->prChild == NULL)
        return pRoot;
    else
        return find_max(pRoot->prChild);
}

BiTreePtr insert_node(int a, BiTreePtr pRoot)
{
    if(pRoot == NULL) {
        pRoot = (BiTreePtr)malloc(sizeof(struct node));
        if( pRoot == NULL)
            printf("out of space!\n");
        else {
            pRoot->data = a;
            pRoot->plChild = pRoot->prChild = NULL;
            
        }
    
    }
    else {
    if(a < pRoot->data)
        pRoot->plChild= insert_node(a,pRoot->plChild);
    else if(a > pRoot->data)
        pRoot->prChild = insert_node(a, pRoot->prChild);
    }
    return pRoot;
}

BiTreePtr delete_node(int a, BiTreePtr &pRoot)
{
    BiTreePtr tmp;
    if(pRoot == NULL)
        printf("this is an empty tree");
    else if(a < pRoot->data)
        pRoot->plChild = delete_node(a, pRoot->plChild);
    else if(a > pRoot->data)
        pRoot->prChild = delete_node(a, pRoot->prChild);
    else if(pRoot->plChild && pRoot->prChild) {
        tmp = find_min(pRoot->prChild);
        pRoot->data = tmp->data;
        pRoot->prChild = delete_node(tmp->data, pRoot->prChild);
    }
    else {
        tmp = pRoot;
        if(pRoot->prChild == NULL)
            pRoot = pRoot->plChild;
        else if(pRoot->plChild == NULL)
            pRoot = pRoot->prChild;
        free(tmp);
    }
    return pRoot;
}