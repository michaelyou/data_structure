#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

typedef struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
}* ptrtonode;

ptrtonode create_polynomial(ptrtonode poly, int num);
int insert_polynomial(ptrtonode poly, int n, int e, int c);
void print_polynomial(ptrtonode poly);
ptrtonode reverse_polynomial(ptrtonode poly);
ptrtonode polynomial_add(ptrtonode poly1, ptrtonode poly2);
ptrtonode polynomial_mult(ptrtonode poly1, ptrtonode poly2);

#include "polynomial.c"
#endif