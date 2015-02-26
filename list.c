/*编译的时候需要使用g++,gcc不支持引用传值
 *这里的实现的链表带头结点，真正的数据从head->next开始
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define bool int
#define false 0
#define true 1


void create_list(Node_t &head,int num)  //num是要创建的节点个数
{
    Node_t p, q;
    if(head != NULL) {
        printf("please delete the old list\n");
        exit(-1);
    }

    p = (Node_t)malloc(sizeof(Node_t));  //头结点
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
    if(n < 1 || n > length(head))
        exit(-1);
    for(i = 0; i < n; i++)
        p = p->next;
    
    printf("the data of the node is %d", p->data);
    printf("\n");
}

Node_t find_node_by_position(Node_t head, int n)
{
    Node_t p;
    if(head == NULL) {
        printf("the list is not exist\n");
        return NULL;
    }
    if(n < 1 || n > length(head))
        return NULL;
        
    p = head;
    int i;
    for(i = 0; i < n && p->next != NULL; i++)
        p = p->next;
    
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

//反转链表
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


/*链表相交，提取两个链表的公共元素，合成新的链表，链表需要事先排好序*/
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

//合并两个链表，重复的元素只保留一个
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

/*从尾到头反过来打印一个链表
 *解法1:从头到尾遍历链表，将结点的值存到栈中，栈是先进后出的，所以从栈中
 *输出的就是逆序的链表
 *解法2:递归在本质上就是一个栈结构，用递归实现
 *下面是用递归实现的代码
 */
void PrintListReversingly_Recursively(Node_t pHead)
{
    if(pHead != NULL)
    {
        if (pHead->next != NULL)
        {
            PrintListReversingly_Recursively(pHead->next);
            printf("%4d ", pHead->next->data);
        }
 
        //printf("%d ", pHead->data);
    }
}



/*在O(1)时间删除结点*/
void DeleteNode(Node_t &pListHead, Node_t pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // 要删除的结点不是尾结点
    if(pToBeDeleted->next!= NULL)
    {
        Node_t pNext = pToBeDeleted->next;
        pToBeDeleted->data = pNext->data;
        pToBeDeleted->next = pNext->next;
 
        free(pNext);
        pNext = NULL;
    }
    // 链表只有一个结点，删除头结点（也是尾结点）
    else if(pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        pListHead = NULL;
    }
    // 链表中有多个结点，删除尾结点
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



/*合并两个已排序的链表(递归实现，链表带头结点)*/
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
/*因为有表头结点，不加此函数，最后打印出的第一个元素就是0，第二个才是
真正的数据*/
Node_t Merge_recursive(Node_t pHead1, Node_t pHead2) {
    Node_t result;
    Node_t tmp = Merge_recursive_core(pHead1, pHead2);
    result = tmp->next;
    return result;
}


/*合并两个已排序链表(非递归实现，链表带头结点)*/
/*这里新建了一个头结点，但是并没有重新建立一个链表，没有额外分配空间*/
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

    cur = head;
    while(pList1 != NULL && pList2 != NULL) {
        if(pList2->data < pList1->data) {
            cur->next = pList2;
            cur = cur->next;
            pList2 = pList2->next;
        }
        else {                          //重估的元素都保留
            cur->next = pList1;
            cur = cur->next;
            pList1 = pList1->next;
        }
    }    
    cur->next = (pList1 == NULL)? pList2 : pList1;

    return head;
}

/*找出链表中倒数第k个结点*/
/*考虑的几点:
  1.head为空指针
  2.以head为头结点的链表，结点数小于k
 */
Node_t find_kth_to_tail(Node_t head, int k)
{
    if(head == NULL || head->next == NULL || k == 0) //设计的计数从0开始
        return NULL;

    int i;
    Node_t p_ahead = head->next;
    Node_t p_behind = head->next;
    
    for(i = 0; i < k - 1; i++) {
        if(p_ahead->next != NULL)      //防止结点数小于k
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


/*找到两个链表的第一个公共结点*/
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

/*删除链表中的重复结点，例如链表为1-2-3-3-4-4-5，删除之后变成1-2-3-4-5*/
void delete_dup_node(Node_t head)
{
    if(head == NULL || head->next == NULL)
        exit(-1);
    Node_t p, q, tmp;
    p = head->next;
    while(p != NULL) {
        q = p->next;
        while(q != NULL) {
            if(q->data == p->data) {
                tmp = q;
                q = q->next;
                p->next = q;
                free(tmp);
            }
            else{               
                break;
            }
        }
        p = p->next;
    }
}


/*删除链表中的重复结点，例如链表为1-2-3-3-4-4-5，删除之后变成1-2-5*/



/*find if there is a loop in the list*/
bool is_loop(Node_t head)
{
    Node_t p_fast = head;
    Node_t p_slow = head;

    //如果无环，则fast先走到终点
    //当链表的长度为奇数时，fast->next为空
    //当链表的长度为偶数时，fast为空
    while(p_fast != NULL && p_fast->next != NULL) {
        p_fast = p_fast->next->next;
        p_slow = p_slow->next;

        if(p_fast == p_slow)
            break;
    }

    if(p_fast == NULL || p_fast->next == NULL)
        return false;
    else
        return true;
}

//计算环的长度
int loop_length(Node_t head)
{
    if(is_loop(head) == false)
        return 0;

    Node_t p_fast = head;
    Node_t p_slow = head;
    bool again = false;
    bool begin = false;
    int length = 0;

    while(true) {
        p_fast = p_fast->next->next;
        p_slow = p_slow->next;

        if(p_fast == p_slow && again == true)
            break;

        if(p_fast == p_slow && again == false) {
            again = true;
            begin = true;
        }

        if(begin == true)
            length++;
            
    }
    return length;
}

//找出环的入口，定理:碰撞点到入口的距离 == 头指针到入口的距离
Node_t find_loop_entrance(Node_t head)
{
    if(is_loop(head) == false)
        return NULL;

    Node_t p_fast = head;
    Node_t p_slow = head;

    while(true) {
        p_fast = p_fast->next->next;
        p_slow = p_slow->next;

        if(p_fast == p_slow)
            break;
    }

    p_slow = head;
    while(p_slow != p_fast) {
        p_slow = p_slow->next;
        p_fast = p_fast->next;
    }

    return p_slow;
}
