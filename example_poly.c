#include <stdio.h>
#include "polynomial.h"

#define NUM 2

int main()
{
    ptrtonode poly1 = NULL; 
    ptrtonode poly2 = NULL;
    ptrtonode result = NULL;
    poly1 = create_polynomial(poly1, NUM);
    poly2 = create_polynomial(poly2, NUM);
    //print_polynomial(poly1);
    //insert_polynomial(poly,4,8,8);
    result = polynomial_mult(poly1, poly2);
    //poly1 = reverse_polynomial(poly1);
    print_polynomial(result);
    
    return 0;
}
