#include <stdio.h>
#include "list.h"

#define NUM 5

int main()
{
    node *head_l = NULL;
    node *head_p = NULL;
    printf("create the lists\n");
    head_l = create_list(head_l, NUM);
    //print_list(head_l);
    head_p = create_list(head_p, NUM);
    //swap_node(find_node_by_position(head_l,2),head_l);
    node *result;
    //result = list_intersect(head_l, head_p);
    result = list_union(head_l, head_p);
    print_list(result);
    return 0;
}
