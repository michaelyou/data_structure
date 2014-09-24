#ifndef _TREE_H
#define _TREE_H


typedef struct node
{
    int data;
    struct node *plChild;
    struct node *prChild;
}*BiTreePtr;

void CreateBiTree(BiTreePtr &pRoot);
void PreTravelBiTree(BiTreePtr pRoot);
void MidTravelBiTree(BiTreePtr pRoot);
void PostTravelBiTree(BiTreePtr pRoot);
int FindDepth(BiTreePtr pRoot);
void FreeBiTree(BiTreePtr pRoot);
BiTreePtr find_element(int a, BiTreePtr pRoot);
BiTreePtr find_min(BiTreePtr pRoot);
BiTreePtr find_max(BiTreePtr pRoot);
BiTreePtr insert_node(int a, BiTreePtr pRoot);
BiTreePtr delete_node(int a, BiTreePtr &pRoot);

#include "tree.c"
#endif





