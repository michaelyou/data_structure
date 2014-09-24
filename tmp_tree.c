#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define EQ(a,b)    ( (a) == (b) )
#define LT(a,b)    ( (a) < (b) )
#define LQ(a,b)    ( (a) <= (b) )
#define FALSE 0
#define TRUE 1

typedef struct treenode
{
    struct treenode *left;
    int data;
    struct treenode *right;
}BiTreenode,* BiTreep;

//初始化二叉树
void init_tree(BiTreep &root)
{
    root=NULL;
    cout<<"初始化成功!"<<endl;
}


int SearchBST(BiTreep &rt, int key, BiTreep father, BiTreep &p)
{
    //在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，
    //若查找成功，则指针p指向该数据元素结点，并返回TRUE，
    //否则指针p指向查找路径上访问的最后一个节点，并返回FALSE，此时指针father指向T的双亲,p=father
    //其初始调用值为NULL
    if(!rt)            //查找不成功
    {
        p=father;
        return FALSE;
    }
    else if(EQ(key,rt->data))        //查找成功
    {
        p=rt;
        return TRUE;
    }
    else if(LT(key,rt->data))
        return SearchBST(rt->left,key,rt,p);    //在左子树中继续查找
    else 
        return SearchBST(rt->right,key,rt,p);    //在右子树中继续查找
}
//创建二叉树
int InsertBST(BiTreep &rt, int key)
{
    //当二叉排序树T中不存在关键字等于key的数据元素时，插入e并返回TRUE，否则返回FALSE
    BiTreep p;
    BiTreep s;
    if(!SearchBST(rt,key,NULL,p))
    {
        s = (BiTreep)malloc(sizeof(BiTreenode));
        s->data=key;
        s->left=s->right=NULL;
        if(!p)
            rt=s;    //被插的树还是空树，被插节点*s做为根节点
        else if(LT(key,p->data))
            p->left=s;        //被插节点*s为左孩子
        else
            p->right=s;        //被插节点*s为右孩子
        return TRUE;
    }
    else
        return FALSE;        //树中已有关键字相同的节点，不再插入
}//InsertBST

//中序遍历二叉树
void mid_order(BiTreep &rt)
{
    if(rt!=NULL)
    {
        mid_order(rt->left);
        cout<<rt->data<<"  ";
        mid_order(rt->right);
    }
}


//查找二叉树中是否存在某元素
int seach_tree(BiTreep &rt,int key)
{
    if(rt==NULL) 
        return FALSE; 
    else 
    { 
        if(rt->data==key) 
            return TRUE;
        else if(LT(key,rt->data))
            return seach_tree(rt->left,key);
        else 
            return seach_tree(rt->right,key);
    }
}

int Delte(BiTreep &p)
{
    if(!p->right)    //右子树空则只需要重接它的左子树
    {
        BiTreep q=p;
        p=p->left;
        free(q);
    }
    else if(!p->left)    //左子树空则只需要重接它的右子树
    {
        BiTreep q=p;
        p=p->right;
        free(q);
    }
    else    //左右子树均不空
    {
        BiTreep father=p;
        BiTreep s=p->left;        //转作，然后一直转右到尽头，就是要删除节点的直接前驱
        while(s->right)
        {
            father=s;
            s=s->right;
        }
        p->data = s->data;        //将直接前驱放置在要删除的节点上，然后删除直接前驱
        if(p == father)        
            p->left = s->left;    //如果直接前驱恰好是被删除节点的左孩子，而且直接前驱的右子树为空,
                                //这样就把直接前驱的左子树连到被删节点的左孩子上。
        else
            father->right = s->left ;    //如果不是上面的情况，那么此时的直接前驱一定是没有右孩子的,
                                        //将其左孩子连接到它的双亲的右子树上。
    }
    return TRUE;
}

//删除节点
int DeletBST(BiTreep &rt,int key)
{
    //若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素节点，并返回TRUE
    //否则返回FALSE
    if(!rt)                //不存在关键字等于key的数据元素
        return FALSE;
    else
    {
        if(EQ(key,rt->data))
            return Delte(rt);        //找到关键字等于key的数据元素，并删除
        else if( LT(key,rt->data) )
            return DeletBST(rt->left,key);
        else
            return DeletBST(rt->right,key);
    }
}//DeletBST

int main()
{
    BiTreep root;
    init_tree(root);        //初始化树

    //插入法创建二叉排序树
    InsertBST(root,45);
    InsertBST(root,24);
    InsertBST(root,53);
    InsertBST(root,45);
    InsertBST(root,12);
    InsertBST(root,24);
    InsertBST(root,90);
    InsertBST(root,8);
    InsertBST(root,30);
    
    //中序遍历二叉树
    cout<<endl<<"中序遍历序列是:"<<endl;
    mid_order(root);
    cout<<endl;

    //删除节点
    DeletBST(root,12);
    DeletBST(root,24);
    DeletBST(root,90);
    mid_order(root);
    cout<<endl;

    //查找二叉树中是否存在某元素
    cout<<"输入要查找的元素!"<<endl;
    int key;
    cin>>key;
    if(seach_tree(root,key)==1)
        cout<<"yes!"<<endl;
    else
        cout<<"no!"<<endl;

    return 0;
}

