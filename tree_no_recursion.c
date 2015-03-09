/*1.��������ǵݹ��㷨*/
#define maxsize 100
typedef struct
{
    Bitree Elem[maxsize];
    int top;
}SqStack;

void PreOrderUnrec(Bitree t)
{
    SqStack s;  
    StackInit(s);  //��ʼ��ջ
    
    p=t;
    while (p!=null || !StackEmpty(s))
    {
        while (p!=null)     //����������
        {
            visite(p->data);
            push(s,p);
            p=p->lchild;      
        }//endwhile
        
        if (!StackEmpty(s)) //ͨ����һ��ѭ���е���Ƕwhileʵ������������
        {
            p=pop(s);
            p=p->rchild;       
        }//endif            
    }//endwhile    
}//PreOrderUnrec



/*��������ǵݹ��㷨*/
#define maxsize 100
typedef struct
{
    Bitree Elem[maxsize];
    int top;
}SqStack;

void InOrderUnrec(Bitree t)
{
    SqStack s;
    StackInit(s);
    p=t;
    while (p!=null || !StackEmpty(s))
    {
        while (p!=null)            //����������
        {
            push(s,p);
            p=p->lchild;
        }//endwhile
        
        if (!StackEmpty(s))
        {
            p=pop(s);
            visite(p->data);       //���ʸ����
            p=p->rchild;           //ͨ����һ��ѭ��ʵ������������
        }//endif      
    }//endwhile
}//InOrderUnrec


/*3.��������ǵݹ��㷨*/
#define maxsize 100
typedef enum{L,R} tagtype;
typedef struct 
{
    Bitree ptr;
    tagtype tag;
}stacknode;

typedef struct
{
    stacknode Elem[maxsize];
    int top;
}SqStack;


//�������
void PostOrderUnrec(Bitree t)
{
    SqStack s;
    stacknode x;
    StackInit(s);
    p=t;

   
    do 
    {
        while (p!=null)       //����������
        {
            x.ptr = p; 
            x.tag = L;        //���Ϊ������
            push(s,x);
            p=p->lchild;
        }
    
        while (!StackEmpty(s) &&s.Elem[s.top].tag==R)  
        {
            x = pop(s);
            p = x.ptr;
            visite(p->data);   //tagΪR����ʾ������������ϣ��ʷ��ʸ����       
        }
        
        if (!StackEmpty(s))
        {
            s.Elem[s.top].tag =R;    //����������
           p=s.Elem[s.top].ptr->rchild;        
        }    
    }while (!StackEmpty(s));
}//PostOrderUnrec

