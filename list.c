/*�����ʱ����Ҫʹ��g++,gcc��֧�����ô�ֵ
 *�����ʵ�ֵ������ͷ��㣬���������ݴ�head->next��ʼ
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define bool int
#define false 0
#define true 1


void create_list(Node_t &head,int num)  //num��Ҫ�����Ľڵ����
{
    Node_t p, q;
    if(head != NULL) {
        printf("please delete the old list\n");
        exit(-1);
    }

    p = (Node_t)malloc(sizeof(Node_t));  //ͷ���
    if(p == NULL)
        exit(-1);
        
    p->data = 0;
    p->next=NULL;
    head = p;

    while(num > 0) {
        q = (Node_t)malloc(sizeof(Node_t));
        if(p == NULL)
            exit(-1);
            
        printf("input the data of the Node_t:");
        scanf("%d", &(q->data));
        p->next = q;
        q->next = NULL;
        p = q;
        num--;
    }
    printf("the list is created\n");
}

void print_list(Node_t head)
{
    Node_t p;
    if(head == NULL)
        printf("the list is not exist\n");
    else {
        p = head;
        p = p->next;
        printf("the data of list is :");
        while(p != NULL) {
            printf("%4d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

/*return true if list is empty*/
bool is_empty(Node_t head)
{
    return head->next == NULL;
}

void add_list(Node_t head, int n)  //add at the tail
{
    Node_t p, q;
    if(head == NULL)
        exit(-1);
    p = head;
    while(p->next != NULL)
        p = p->next;
    while(n > 0) {
        q = (Node_t)malloc(sizeof(Node_t));
        if(p == NULL)
            exit(-1);
            
        printf("input the value of new Node_t:");
        scanf("%d", &(q->data));
        p->next = q;
        q->next = NULL;
        p = q;
        n--;
    }
}

Node_t delete_list(Node_t head, int i)
{
    Node_t p, q;
    int a;
    if(head == NULL)
        return NULL;
    if(i < 0 || i > length(head))
        return NULL;
    p = head;
    a = i - 1;
    while(a > 0) {
        p = p->next;
        a--;
    }
    q = p->next;
    p->next = q->next;
    free(q);  
}


int length(Node_t head)
{
    Node_t p;
    int n = 0;
    if(head == NULL)
        return 0;

    p = head->next;    
    while(p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

int insert_list(Node_t head, int a, int e)
{
    Node_t p, q;
    if(head == NULL)
        return 0;
    else if(a > (length(head) + 1)) //make it possible to insert at the tail
        return -1;
    else {
        p = head;
        a--;
        while(a > 0) {
            p = p->next;
            a--;
        }
        q = (Node_t)malloc(sizeof(Node_t));
        q->data = e;
        q->next = p->next;
        p->next = q;
        return 1;
    }
}


//updata means change the data of a specific node
int update_list(Node_t head, int a, int e) 
{
    Node_t p;
    if(head == NULL)
        return 0;
    else if(a > length(head))
        return -1;
    else {
        p = head;
        while(a > 0) {
            p = p->next;
            a--;
        }
        p->data = e;
        return -1;
    }
}


void destroy_list(Node_t head)
{
    Node_t p, q;
    q = p =head;
   
    while(p != NULL) {
        p = p->next;
        free(q);
        q = p;
    }
    printf("the list has been destroyed");    
}


int search_list(Node_t head,int e)
{
    Node_t p;
    int n = 0;
    if(head == NULL)
        return 0;
    p = head;
    while(p->next != NULL) {
        p = p->next;
        if(p->data == e) {
            n++;
            return n;
        }
        n++;
    }
    return -1;
}

void printnodes(Node_t head, int n)  /* n is the position of the node*/
{
    Node_t p;
    if(head == NULL)
        printf("the list is not exist\n");
    p = head;
    int i;
    for(i = 0; i < n && p->next != NULL; i++)
        p = p->next;
    if(p->next == NULL && i != n) {
        printf("\n");
        printf("the list is not long enough\n");
    }
    else
        printf("%4d", p->data);
}

Node_t find_node_by_position(Node_t head, int n)
{
    Node_t p;
    if(head == NULL) {
        printf("the list is not exist\n");
        return NULL;
    }
    p = head;
    int i;
    for(i = 0; i < n && p->next != NULL; i++)
        p = p->next;
    if(p->next == NULL && i != n) {
        printf("can't find the right data\n");
        return NULL;
    }
    else
        return p;
}

void swap_node(Node_t beforep,Node_t head)
{
    Node_t p, afterp;
    p = beforep->next;
    afterp = p->next;

    beforep->next = afterp;
    p->next = afterp->next;
    afterp->next = p;    
}

void printlots(Node_t head_l, Node_t head_p)
{
     Node_t p;
     if(head_p == NULL)
        printf("no need to print\n");
     p = head_p;
     p = p->next;
     while(p != NULL) {
        //printf("%d", head_l->next->data);
        printnodes(head_l, p->data);
        //printf("%d", head_l->next->data);
        p = p->next;
     }
     printf("\n");
}

//��ת����
Node_t reverse_list(Node_t head)  //travel the link
{
    Node_t p, q;
    if(head == NULL)
        return NULL;
    printf("the old list is:");
    print_list(head);

    p = head->next;
    while(p != NULL && p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        q->next = head->next;
        head->next = q;
    }   
}


/*�����ཻ����ȡ��������Ĺ���Ԫ�أ��ϳ��µ�����������Ҫ�����ź���*/
Node_t list_intersect(Node_t head_q,Node_t head_p)
{
    Node_t q, p;
    Node_t result = NULL;
    int i = 1;
    create_list(result, 0);
    if(head_q == NULL || head_p == NULL)
        return NULL;
    q = head_q->next;
    p = head_p->next;

    while(q != NULL && p != NULL) {
        if(q->data > p->data)
            p = p->next;
        else if(p->data > q->data)
            q = q->next;
        else {
            insert_list(result, i, q->data);
            q = q->next;
            if(q == NULL)
            {
                return result;
            }
            else {
                while(q->data == p->data) {
                    q = q->next;
                    if(q == NULL)
                        return result;
                }
            }
            p = p->next;
            i++;
        }
    }
    return result;
    
}

//�ϲ����������ظ���Ԫ��ֻ����һ��
Node_t list_union(Node_t head_q,Node_t head_p)
{
    Node_t p, q;
    Node_t result = NULL;
    int i = 1;
    create_list(result, 0);
    p = head_p->next;

    while(p != NULL) {
        int flag = 0;
        q = head_q->next;

        while(q != NULL) {
            if(p->data == q->data) {
                flag = 1;
                break;
            }
            else
                q = q->next;
        }

        if(flag == 0) {
            insert_list(result, i, p->data);
            i++;
        }
        p = p->next;
    }
    q = head_q->next;
    while(q != NULL) {
        insert_list(result, i, q->data);
        i++;
        int tmp = q->data;
        q = q->next;
        if(q != NULL) {
            while(q != NULL && q->data == tmp)
                q = q->next;
        }
    }
    
    return result;
}

/*��β��ͷ��������ӡһ������
 *�ⷨ1:��ͷ��β��������������ֵ�浽ջ�У�ջ���Ƚ�����ģ����Դ�ջ��
 *����ľ������������
 *�ⷨ2:�ݹ��ڱ����Ͼ���һ��ջ�ṹ���õݹ�ʵ��
 *�������õݹ�ʵ�ֵĴ���
 */
void PrintListReversingly_Recursively(Node_t pHead)
{
    if(pHead != NULL)
    {
        if (pHead->next != NULL)
        {
            PrintListReversingly_Recursively(pHead->next);
            printf("%d ", pHead->next->data);
        }
 
        //printf("%d ", pHead->data);
    }
}

/*��O(1)ʱ��ɾ�����*/
void DeleteNode(Node_t &pListHead, Node_t pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // Ҫɾ���Ľ�㲻��β���
    if(pToBeDeleted->next!= NULL)
    {
        Node_t pNext = pToBeDeleted->next;
        pToBeDeleted->data = pNext->data;
        pToBeDeleted->next = pNext->next;
 
        delete pNext;
        pNext = NULL;
    }
    // ����ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
    else if(pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        pListHead = NULL;
    }
    // �������ж����㣬ɾ��β���
    else
    {
        Node_t pNode = pListHead;
        while(pNode->next != pToBeDeleted)
        {
            pNode = pNode->next;            
        }
 
        pNode->next = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}



/*�ϲ����������������(�ݹ�ʵ�֣������ͷ���)*/
Node_t Merge_recursive_core(Node_t pHead1, Node_t pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    Node_t pMergedHead = NULL;

    if(pHead1->data < pHead2->data)
    {
        pMergedHead = pHead1;
        pMergedHead->next = Merge_recursive_core(pHead1->next, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->next = Merge_recursive_core(pHead1, pHead2->next);
    }

    return pMergedHead;  
}
/*��Ϊ�б�ͷ��㣬���Ӵ˺���������ӡ���ĵ�һ��Ԫ�ؾ���0���ڶ�������
����������*/
Node_t Merge_recursive(Node_t pHead1, Node_t pHead2) {
    Node_t result;
    Node_t tmp = Merge_recursive_core(pHead1, pHead2);
    result = tmp->next;
    return result;
}


/*�ϲ���������������(�ǵݹ�ʵ�֣������ͷ���)*/
/*�����½���һ��ͷ��㣬���ǲ�û�����½���һ������û�ж������ռ�*/
Node_t Merge_iterative(Node_t pHead1, Node_t pHead2)
{
    Node_t head = NULL, cur, pList1, pList2;
    
    pList1 = pHead1->next;
    pList2 = pHead2->next;
    if(pHead1 == NULL || pList1 == NULL)
        return pHead2;
    if(pHead2 == NULL || pList2 == NULL)
        return pHead1;

    create_list(head, 0);
    
    for(cur = head; pList1 != NULL && pList2 != NULL;) {
        if(pList2->data < pList1->data) {
            cur->next = pList2;
            cur = cur->next;
            pList2 = pList2->next;
        }
        else {
            cur->next = pList1;
            cur = cur->next;
            pList1 = pList1->next;
        }
    }    
    cur->next = (pList1 == NULL)? pList2 : pList1;

    return head;
}

/*�ҳ������е�����k�����*/
/*���ǵļ���:
  1.headΪ��ָ��
  2.��headΪͷ�������������С��k
 */
Node_t find_kth_to_tail(Node_t head, int k)
{
    if(head == NULL || head->next == NULL || k == 0) //��Ƶļ�����0��ʼ
        return NULL;

    int i;
    Node_t p_ahead = head->next;
    Node_t p_behind = head->next;
    
    for(i = 0; i < k - 1; i++) {
        if(p_ahead->next != NULL)
            p_ahead = p_ahead->next;
        else
            return NULL;
    }
    
    while(p_ahead->next != NULL) {
        p_ahead = p_ahead->next;
        p_behind = p_behind->next;
    }
   

    return p_behind;
}


/*�ҵ���������ĵ�һ���������*/
Node_t find_first_common_node(Node_t head1, Node_t head2)
{
    if(head1 == NULL || head2 == NULL)
        return NULL;
    Node_t p_list_long = head1->next;
    Node_t p_list_short = head2->next;
    int length1 = length(head1); 
    int length2 = length(head2);
    int nlengthdif = length1 - length2;
    
    if(length1 < length2) {
        p_list_long = head2->next;
        p_list_short = head1->next;
        nlengthdif = length2 - length1;
    }

    int i;
    for(i = 0; i < nlengthdif; i++) {
        p_list_long = p_list_long->next;
    }

    while((p_list_short != NULL) && 
          (p_list_short != NULL) &&
          (p_list_short != p_list_long)) {
        p_list_short = p_list_short->next;
        p_list_long = p_list_long->next;
    }
   
    Node_t first_common_node = p_list_long;
    return first_common_node;
   
}

/*ɾ�������е��ظ���㣬��������Ϊ1-2-3-3-4-4-5��ɾ��֮����1-2-5*/

/*find if there is a loop in the list*/
//int find_loop()
