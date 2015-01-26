#define elementtype int

void insert_sort(elementtype *array, int n) {
    elementtype tmp;
    int p, j;
    for(p = 1; p < n; p++) {
        tmp = array[p];
        for(j = p; j > 0 && array[j - 1] > tmp; j--) {
            array[j]= array[j - 1];
        }
        array[j] = tmp;
    }
}


void shell_sort(elementtype *array, int n) {
    elementtype tmp;
    int increment, i, j;
    for(increment = n/2; increment > 0; increment /= 2) {
        for(i = increment; i < n; i++) {
            tmp = array[i];
            for(j = i; j >= increment; j -= increment)
                if(tmp < array[j - increment])
                    array[j] = array[j - increment];
                else
                    break;
             array[j] = tmp;
        }
    }
}

/****************heap-sort**************************/

#define LeftChild(i) (2 * (i) + 1)
void max_heapify(int *a, int index, int size)
{
    int child;

    int tmp = a[index];

    for(; LeftChild(index) < size ; index = child)
    {
        child = LeftChild(index);
        if(child != size - 1 && a[child] < a[child + 1])
                child ++;

        /***************************
         * 提升儿子到父结点，
         * 儿子结点的位置上存在空穴，
         * 需要继续比较
         **************************/
        if(a[child] > tmp)
                a[index] = a[child];
        else/*不需要提升*/
                break;
    }
    /*保存结点的位置找到*/
    a[index] = tmp;
}

void build_maxheap(int *a, int size)
{
    int step = 0;

    /***************************************
     * (size-1)/2实质是找到a[size-1]的父结点，
     * 也就是倒数第二层，堆的创建过程是一个
     * 由低层到高层逐渐创建的过程
     **************************************/
    for(step = (size - 1) / 2 ; step >= 0; -- step)
        max_heapify(a, step, size);
}

void heap_sort(int *a, int size)
{
    int i = 0;
    /*创建堆*/
    build_maxheap(a,size);

    for(; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    for(i = size - 1; i > 0; --i)
    {
        /*swap(a[i],a[0])*/
        a[i] = a[i] + a[0];
        a[0] = a[i] - a[0];
        a[i] = a[i] - a[0];
        /*更新堆的结构*/
        max_heapify(a,0,i);
        
        
        
        //printf("%d ", a[17]);
        //printf("\n");
    }
    for(; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/**********************************************/


void merge_sort(int * a, int left, int right)
{
    int i = 0;
    int *atmp = NULL;
    int *Actr = NULL, *Bctr = NULL, *Cctr = NULL;

    /*递归退出条件*/
    if(left >= right)
        return;

    atmp = (int *)calloc((right - left + 1) / 2,sizeof(int));
    if(NULL == atmp)
        return;

    for(i = 0; i < (right - left + 1) / 2 ; ++ i)
        atmp[i] = a[left + i]; 

    merge_sort(atmp,0,i - 1); 
    merge_sort(a, left + i, right);

    Actr = atmp;
    Bctr = a + left + i;
    Cctr = a + left;

    while(Actr != atmp + i && Bctr != a + right + 1)
    { 
        if(*Actr <= *Bctr)
            *Cctr++ = *Actr++;
        else
            *Cctr++ = *Bctr++;
    } 
    while(Actr != atmp + i)
        *Cctr ++ = *Actr++;
    while(Bctr != a + right + 1)
        *Cctr ++ = *Bctr ++;

    free(atmp);
    atmp = NULL;
}

/*******************快速排序***********************/
/*数据交换*/
void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quick_sort(int list[],int left,int right)
{
   int key,i,j,k;
   if(left < right)
   {
      k = choose_pivot(left,right);
      swap(&list[left],&list[k]);
      key = list[left];
      i = left+1;
      j = right;
      while(i <= j)
      {
         while((i <= right) && (list[i] <= key))
                i++;
         while((j >= left) && (list[j] > key))
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
     // 交换两个元素的位置
      swap(&list[left],&list[j]);
     // 递归地对较小的数据序列进行排序
      quick_sort(list,left,j-1);
      quick_sort(list,j+1,right);
   }
}

