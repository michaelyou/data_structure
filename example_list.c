#include <stdio.h>
#include "list.h"

#define NUM 5

int main()
{
    Node_t head_l = NULL;
    Node_t nod = NULL;
    //Node_t head_p = NULL;
    printf("create the lists\n");
    create_list(head_l, NUM);
    delete_dup_node(head_l);
    //nod = find_node_by_position(head_l, 5);
    //DeleteNode(head_l, nod);
    //print_list(head_l);
    //create_list(head_p, NUM);
    //swap_node(find_node_by_position(head_l,2),head_l);
    //Node_t pToBeDeleted = head_l;
    //DeleteNode(head_l,  pToBeDeleted);
    //Node_t result;
    //result = list_intersect(head_l, head_p);
    //result = list_union(head_l, head_p);
    //result = Merge_recursive(head_l, head_p);
    //head_l = reverse_list(head_l);
    //add_list(head_l, 1);
    //reverse_list(head_l);
    //print_list(head_l);
    print_list(head_l);
    //print_list(result);
    //printnodes(head_l, 3);
    #if 0
    printf("%d \n", length(head_p));
    print_list(head_p);
    result = find_kth_to_tail(head_p, 0);
    if(result != NULL)
        printf("%d", result->data);
    #endif
    //PrintListReversingly_Recursively(result);
    return 0;
}
