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

//��ʼ��������
void init_tree(BiTreep &root)
{
    root=NULL;
    cout<<"��ʼ���ɹ�!"<<endl;
}


int SearchBST(BiTreep &rt, int key, BiTreep father, BiTreep &p)
{
    //�ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ�
    //�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE��
    //����ָ��pָ�����·���Ϸ��ʵ����һ���ڵ㣬������FALSE����ʱָ��fatherָ��T��˫��,p=father
    //���ʼ����ֵΪNULL
    if(!rt)            //���Ҳ��ɹ�
    {
        p=father;
        return FALSE;
    }
    else if(EQ(key,rt->data))        //���ҳɹ�
    {
        p=rt;
        return TRUE;
    }
    else if(LT(key,rt->data))
        return SearchBST(rt->left,key,rt,p);    //���������м�������
    else 
        return SearchBST(rt->right,key,rt,p);    //���������м�������
}
//����������
int InsertBST(BiTreep &rt, int key)
{
    //������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ������e������TRUE�����򷵻�FALSE
    BiTreep p;
    BiTreep s;
    if(!SearchBST(rt,key,NULL,p))
    {
        s = (BiTreep)malloc(sizeof(BiTreenode));
        s->data=key;
        s->left=s->right=NULL;
        if(!p)
            rt=s;    //����������ǿ���������ڵ�*s��Ϊ���ڵ�
        else if(LT(key,p->data))
            p->left=s;        //����ڵ�*sΪ����
        else
            p->right=s;        //����ڵ�*sΪ�Һ���
        return TRUE;
    }
    else
        return FALSE;        //�������йؼ�����ͬ�Ľڵ㣬���ٲ���
}//InsertBST

//�������������
void mid_order(BiTreep &rt)
{
    if(rt!=NULL)
    {
        mid_order(rt->left);
        cout<<rt->data<<"  ";
        mid_order(rt->right);
    }
}


//���Ҷ��������Ƿ����ĳԪ��
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
    if(!p->right)    //����������ֻ��Ҫ�ؽ�����������
    {
        BiTreep q=p;
        p=p->left;
        free(q);
    }
    else if(!p->left)    //����������ֻ��Ҫ�ؽ�����������
    {
        BiTreep q=p;
        p=p->right;
        free(q);
    }
    else    //��������������
    {
        BiTreep father=p;
        BiTreep s=p->left;        //ת����Ȼ��һֱת�ҵ���ͷ������Ҫɾ���ڵ��ֱ��ǰ��
        while(s->right)
        {
            father=s;
            s=s->right;
        }
        p->data = s->data;        //��ֱ��ǰ��������Ҫɾ���Ľڵ��ϣ�Ȼ��ɾ��ֱ��ǰ��
        if(p == father)        
            p->left = s->left;    //���ֱ��ǰ��ǡ���Ǳ�ɾ���ڵ�����ӣ�����ֱ��ǰ����������Ϊ��,
                                //�����Ͱ�ֱ��ǰ����������������ɾ�ڵ�������ϡ�
        else
            father->right = s->left ;    //�������������������ô��ʱ��ֱ��ǰ��һ����û���Һ��ӵ�,
                                        //�����������ӵ�����˫�׵��������ϡ�
    }
    return TRUE;
}

//ɾ���ڵ�
int DeletBST(BiTreep &rt,int key)
{
    //������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽڵ㣬������TRUE
    //���򷵻�FALSE
    if(!rt)                //�����ڹؼ��ֵ���key������Ԫ��
        return FALSE;
    else
    {
        if(EQ(key,rt->data))
            return Delte(rt);        //�ҵ��ؼ��ֵ���key������Ԫ�أ���ɾ��
        else if( LT(key,rt->data) )
            return DeletBST(rt->left,key);
        else
            return DeletBST(rt->right,key);
    }
}//DeletBST

int main()
{
    BiTreep root;
    init_tree(root);        //��ʼ����

    //���뷨��������������
    InsertBST(root,45);
    InsertBST(root,24);
    InsertBST(root,53);
    InsertBST(root,45);
    InsertBST(root,12);
    InsertBST(root,24);
    InsertBST(root,90);
    InsertBST(root,8);
    InsertBST(root,30);
    
    //�������������
    cout<<endl<<"�������������:"<<endl;
    mid_order(root);
    cout<<endl;

    //ɾ���ڵ�
    DeletBST(root,12);
    DeletBST(root,24);
    DeletBST(root,90);
    mid_order(root);
    cout<<endl;

    //���Ҷ��������Ƿ����ĳԪ��
    cout<<"����Ҫ���ҵ�Ԫ��!"<<endl;
    int key;
    cin>>key;
    if(seach_tree(root,key)==1)
        cout<<"yes!"<<endl;
    else
        cout<<"no!"<<endl;

    return 0;
}

