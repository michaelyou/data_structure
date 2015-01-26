#include <stdio.h>
#include "list.h"

#define NUM 5

int main()
{
    node head_l = NULL;
    node head_p = NULL;
    printf("create the lists\n");
    create_list(head_l, NUM);
    //print_list(head_l);
    create_list(head_p, NUM);
    //swap_node(find_node_by_position(head_l,2),head_l);
    //node pToBeDeleted = head_l;
    //DeleteNode(head_l,  pToBeDeleted);
    node result;
    //result = list_intersect(head_l, head_p);
    //result = list_union(head_l, head_p);
    result = Merge(head_l, head_p);
    //head_l = reverse_list(head_l);
    //add_list(head_l, 1);
    //reverse_list(head_l);
    //print_list(head_l);
    print_list(head_l);
    print_list(result);
    //PrintListReversingly_Recursively(result);
    return 0;
}
