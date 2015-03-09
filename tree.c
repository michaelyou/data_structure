#include "tree.h"

void CreateBiTree(BiTreePtr &pRoot) //这里是传pRoot的地址，这样就是地址传递了
{                                   //修改了pRoot的值，可以同步，用*也可以实现
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

/*这里的前序，中序，后序遍历采用的都是递归算法。如果不使用递归算法，可以使用
栈来取代递归*/  
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


/*已知前序遍历和中序遍历，建立二叉树*/
BiTreePtr ConstructCore
(
    int* startPreorder, int* endPreorder, 
    int* startInorder, int* endInorder
)
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BiTreePtr root = (BiTreePtr)malloc(sizeof(struct node));
    root->data = rootValue;
    root->plChild = root->prChild = NULL;

    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            printf("Invalid input.\n");
    }

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
        printf("Invalid input.");

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->plChild= ConstructCore(startPreorder + 1, leftPreorderEnd, 
            startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->prChild= ConstructCore(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}

BiTreePtr Construct(int* preorder, int* inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;

    return ConstructCore(preorder, preorder + length - 1,
        inorder, inorder + length - 1);
}

/*写一个函数，输入一个二叉树，树中每个结点存放了一个整数值，函数
 *返回这颗二叉树中相差最大的两个结点之间的差的绝对值
 */
#define MAX_INF 100000
#define MIN_INF -10000
int find_max_diff(node *root)
{
    static int min = MAX_INF;//初始化为一个足够大的值
    static int max = MIN_INF;//初始化为一个足够小的值
    if (root->data < min)
        min = root->data;
    if (root->data > max)
        max = root->data;
    if (root->plChild != NULL)
        find_max_diff(root->plChild);
    if (root->prChild!= NULL)
        find_max_diff(root->prChild);
    return max - min;
}

