#include "polynomial.h"
#include <stdlib.h>

ptrtonode create_polynomial(ptrtonode poly,int num)
{
    ptrtonode p;
    ptrtonode q;
    if(poly != NULL) {
        printf("please clear the list\n");
        return NULL;
    }

    q = (ptrtonode)malloc(sizeof(struct Node)); /*建立头结点，初始化*/
    q->coefficient = 0;
    q->exponent = 0;
    q->next = NULL;
    poly = q;
    
    while(num >0) {
        p = (ptrtonode)malloc(sizeof(struct Node));
        printf("please input the coefficent of the polynomial\n");
        scanf("%d", &(p->coefficient));
        printf("please input the exponent of the polynomial\n");
        scanf("%d", &(p->exponent));

        q->next = p;
        p->next = NULL;
        q = p;
        num--;
    }
    printf("the polynomial is created\n");
    return poly;
}

int insert_polynomial(ptrtonode poly, int a, int c, int e)
{
    ptrtonode p, q;
    if(poly == NULL)
        return 0;
    else {
        p = poly;
        a--;
        while(a > 0) {
            p = p->next;
            a--;
        }
        q = (ptrtonode)malloc(sizeof(struct Node));
        q->coefficient = c;
        q->exponent = e;
        q->next = p->next;
        p->next = q;
        return 1;
    }
}

void print_polynomial(ptrtonode poly)
{
    ptrtonode p;
    if(poly == NULL)
        printf("the list is empty\n");

    else {
        p = poly;
        p = p->next;
        printf("the polynomial is :");
        while(p->next != NULL) {
            printf("%dn^%d + ", p->coefficient, p->exponent);
            p = p->next;
        }
        printf("%dn^%d", p->coefficient, p->exponent);
        printf("\n");
    }
}

ptrtonode polynomial_mult(ptrtonode poly1, ptrtonode poly2)
{
    ptrtonode p, q, result = NULL;
    int expo_max = 0;
    int expo = 0;
    result = create_polynomial(result, 0);
    p = poly1->next;
    q = poly2->next;
    if(p != NULL && q != NULL) 
        expo_max = p->exponent + q->exponent;
    q = reverse_polynomial(poly2);
    q = q->next;
    int k;
    int i = 1;
    for(k = expo_max; k > 0; k--) {
        p = poly1->next;
        while(p != NULL && p->exponent > k)
            p = p->next;
        q = poly2->next;
        while(p != NULL && q != NULL && (q->exponent + p->exponent < k) )
            q = q->next;
        while(q != NULL && p != NULL) {
            if(p->exponent + q->exponent == k) {
                expo += p->coefficient * q->coefficient;
                p = p->next;
                q = q->next;
            }
            else if(p->exponent + q->exponent < k) 
                q = q->next;
            else
                p = p->next;
        }
        if(expo != 0) {
            insert_polynomial(result, i, expo, k);
            i++;
            expo = 0;
        }
    }

    return result;
}

ptrtonode polynomial_add(ptrtonode poly1, ptrtonode poly2)
{
    ptrtonode result = NULL;
    int i = 1;
    int temp;
    result = create_polynomial(result, 0);

    ptrtonode p, q;
    if(poly1 != NULL && poly2 != NULL) {
        p = poly1->next;
        q = poly2->next;
    }

    while(p != NULL && q != NULL) {
        if(p->exponent > q->exponent) {
            insert_polynomial(result, i, p->coefficient, p->exponent);
            p = p->next;
            i++;
        }
        else if(p->exponent < q->exponent) {
            insert_polynomial(result, i, q->coefficient, q->exponent);
            q = q->next;
            i++;
        }
        else {
            temp = p->coefficient + q->coefficient;
            if(temp != 0) {
                insert_polynomial(result, i, temp, q->exponent);
                p = p->next;
                q = q->next;
                i++;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
    }
    return result;    
}

ptrtonode reverse_polynomial(ptrtonode poly)
{
    ptrtonode p, q;
    p = poly->next;
    
    poly->next = NULL;
    while(p != NULL) {
        q = p->next;
        p->next = poly->next;
        poly->next = p;
        p = q;
    }
    return poly;
}