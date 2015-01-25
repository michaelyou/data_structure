/*编译的时候需要使用g++,gcc不支持引用传值*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void create_list(node &head,int num)  //num是要创建的节点个数
{
    node p, q;
    if(head != NULL) {
        printf("please delete the old list\n");
        exit(-1);
    }

    p = (node)malloc(sizeof(node));  //头结点
    p->data = 0;
    p->next=NULL;
    head = p;

    while(num > 0) {
        q = (node)malloc(sizeof(node));
        printf("input the number of the node:");
        scanf("%d", &(q->data));
        p->next = q;
        q->next = NULL;
        p = q;
        num--;
    }
    printf("the list is created\n");
}

void print_list(node head)
{
    node p;
    if(head == NULL)
        printf("the list is empty\n");
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

void add_list(node &head, int n)  //add at the tail
{
    node p, q;
    if(head = NULL)
        exit(-1);
    p = head;
    while(p->next != NULL)
        p = p->next;
    while(n > 0) {
        q = (node)malloc(sizeof(node));
        printf("input the value of new node:");
        scanf("%d", q->data);
        p->next = q;
        q->next = NULL;
        p = q;
        n--;
    }
}

int delete_list(node head, int i)
{
    node p, q;
    int a;
    if(head == NULL)
        return -1;
    if(i < 0 || i > length(head))
        return 0;
    p = head;
    a = i - 1;
    while(a > 0) {
        p = p->next;
        a--;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    if(length(head) == 0) {
        free(head);
        return 2;
    }
    return 1;   
}

int length(node head)
{
    node p;
    int n = 0;
    if(head == NULL)
        return 0;

    p = head;
    while(p != NULL) {
        p = p->next;
        n++;
    }
    return n;
}

int insert_list(node head, int a, int e)
{
    node p, q;
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
        q = (node)malloc(sizeof(node));
        q->data = e;
        q->next = p->next;
        p->next = q;
        return 1;
    }
}

int update_list(node head, int a, int e) //updata means change the data of a specific node
{
    node p;
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

node destroy_list(node head)
{
    node p, q;
    q = p =head;
    if(head = NULL) {
        printf("the list is empty\n");
        return NULL;
    }

    while(p != NULL) {
        p = p->next;
        free(q);
        q = p;
    }
    printf("the list has been destroyed");
    return NULL;
}

int search_list(node head,int e)
{
    node p;
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

void printnodes(node head, int n)  /* n is the position of the node*/
{
    node p;
    if(head == NULL)
        printf("the list is empty\n");
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

node find_node_by_position(node head, int n)
{
    node p;
    if(head == NULL) {
        printf("the list is empty\n");
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

void swap_node(node beforep,node head)
{
    node p, afterp;
    p = beforep->next;
    afterp = p->next;

    beforep->next = afterp;
    p->next = afterp->next;
    afterp->next = p;    
}

void printlots(node head_l, node head_p)
{
     node p;
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

node reverse_list(node head)  //travel the link
{
    node p, q;
    if(head == NULL)
        return NULL;
    printf("the old list is:");
    print_list(head);

    p = head->next;
    head->next = NULL;
    while(p != NULL)
    {
        q = p->next;
        p->next = head->next;
    }
    return head;
}

node list_intersect(node head_q,node head_p)
{
    node q, p;
    node result = NULL;
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

node list_union(node head_q,node head_p)
{
    node p, q;
    node result = NULL;
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

/*从尾到头反过来打印一个链表
 *解法1:从头到尾遍历链表，将结点的值存到栈中，栈是先进后出的，所以从栈中
 *输出的就是逆序的链表
 *解法2:递归在本质上就是一个栈结构，用递归实现
 *下面是用递归实现的代码
 */
void PrintListReversingly_Recursively(node pHead)
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