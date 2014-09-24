#include <stdio.h>
#include "queue.h"

#define CAP 10
int main()
{
   int i = 1;
   int n;
   int j;
   queue_t p;
   queue_t *q = &p;
   queue_init(q, CAP);
   queue_push(q, i);
   printf("input the level of yanghui_triangle:\n");
   scanf("%d", &n);
   for(i = 0; i <= n; i++) {
        int t = 0;
        queue_push(q, t);
        int s;
        for(j = 0; j < i+2; j++) {
            int tmp;
            s = queue_front(q);
            tmp = t + s;
            queue_pop(q);
            queue_push(q, tmp);
            t = s;
            if(j != i + 1)
                printf("%d ", t);
        }
        printf("\n");
        
   }
   return 0;
}
