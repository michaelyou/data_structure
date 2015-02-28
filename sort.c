#define elementtype int

/*排序算法的稳定性:原本键值一样的元素排序后相对位置不变*/

/*数据交换*/
void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}


//冒泡排序最坏情况为将逆序排成正序，此时比较交换次数为n*(n-1)/2，时间
//复杂度为O(n^2)
void bubble_sort(elementtype *array, int n) {
    elementtype tmp;
    int i = 0, j = 0;
    for(; i < n - 1; i++) {
        for(j = n -1; j > i; j--) {
            if(array[j] < array[j - 1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
}



//选择排序
//选择排序是和冒泡排序差不多的一种排序。和冒泡排序交换相连数据不一样
//的是，选择排序只有在确定了最小的数据之后，才会发生交换
/*选择排序的时间复杂度为O(n^2),是不稳定的排序算法，例如数组为5,5,3，
第一次就会将第一个5和3交换。*/
void select_sort(elementtype *array, int n) {
    elementtype tmp;
    int i, j, index;
    if(array == NULL && n < 0)
        exit(-1);

    for(i = 0; i < n - 1; i++) {
        index = i;
        for(j = i + 1; j < n; j ++) {
            if(array[j] < array[index])
                index = j;
        }

        if(index != i) {
            swap(array[i], array[index]);
        }
    }
}


//插入排序
/*
有一个已经有序的数据序列，要求在这个已经排好的数据序列中插入一个数，
但要求插入后此数据序列仍然有序，这个时候就要用到一种新的排序方法——
插入排序法,插入排序的基本操作就是将一个数据插入到已经排好序的有序数据
中，从而得到一个新的、个数加一的有序数据，算法适用于少量数据的排序，
时间复杂度为O(n^2)。是稳定的排序方法。
插入算法把要排序的数组分成两部分：第一部分包含了这个数组的所有元素，
但将最后一个元素除外（让数组多一个空间才有插入的位置），
而第二部分就只包含这一个元素（即待插入元素）。在第一部分排序完成后，
再将这个最后元素插入到已排好序的第一部分中。
 */
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


/*
Shell排序是DL. Shell于1959年针对直接插入排序算法改进提出的，
属于插入排序的范畴，是对直接插入排序算法的改进。
直接插入排序在基本有序时效率较高，并且在序列规模不是很大时效率也很高，
Shell排序就是针对这两点进行改进。核心思想是：待排序列有n个元素，
先取一个小于n的整数h1作为第一个增量，把待排序列以间隔h1分成若干子序列，
子序列内使用插入排序；然后取第二个增量h2(< h1)，重复上述的划分和排序，
直至所取的增量hl = 1 (h1 > h2 > ... > hl)。

这样不管序列多么庞大，在先前较大步长分组下每个子序列规模都不是很大，
用直接插入效率很高；后面步长变小，子序列变大，
但由于整体有序性越来越明显，排序效率依然很高，大大提高了时间效率。
 */
void shell_sort(elementtype *array, int n) {
    elementtype tmp;
    int increment, i, j;
    for(increment = n/2; increment > 0; increment /= 2) {
        for(i = increment; i < n; i++) {
            tmp = array[i];
            for(j = i; j >= increment && array[j - increment] > tmp; j -= increment)
                    array[j] = array[j - increment];

            array[j] = tmp;
        }
    }
}



/****************heap-sort**************************/

#define LeftChild(i) (2 * (i) + 1)
void perc_down(int *a, int i, int size)
{
    int child;

    int tmp = a[i];

    for(; LeftChild(i) < size ; i = child)
    {
        child = LeftChild(i);
        if(child != size - 1 && a[child] < a[child + 1])
                child ++;

        /***************************
         * 提升儿子到父结点，
         * 儿子结点的位置上存在空穴，
         * 需要继续比较
         **************************/
        if(a[child] > tmp)
                a[i] = a[child];
        else/*不需要提升*/
                break;
    }
    /*保存结点的位置找到*/
    a[i] = tmp;
}
/*大根堆*/
void build_maxheap(int *a, int size)
{
    int step = 0;

    /***************************************
     * (size-1)/2实质是找到a[size-1]的父结点，
     * 也就是倒数第二层，堆的创建过程是一个
     * 由低层到高层逐渐创建的过程
     **************************************/
    for(step = (size - 1) / 2 ; step >= 0; -- step)
        perc_down(a, step, size);
}

void heap_sort(int *a, int size)
{
    int i = 0;
    /*创建堆*/
    build_maxheap(a,size);

    for(; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    for(i = size - 1; i > 0; i--)
    {
        swap(a[i],a[0]);
        /*更新堆的结构*/
        perc_down(a,0,i);
        
    }
   
}



/**********************************************/
//归并排序

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


int median3(int *array, int left, int right)
{
    int center = (left + right) / 2;
    
    if(array[left] > array[center])
        swap(&array[left], &array[center]);
    if(array[left] > array[right])
        swap(&array[left], &array[right]);
    if(array[center] > array[right])
        swap(&array[center], &array[right]);

    swap(&array[center], &array[right - 1]);

    return array[right - 1];
}

/*递归和分治*/
#define Cutoff 3
void quick_sort(int list[],int left,int right)
{
   //median3需要数组至少有4个数，left，right，middle，right-1
   if(left + Cutoff <= right)   
   {
      int key,i,j;
      key = median3(list,left,right);
      
      i = left;
      j = right - 1;
      
      while(1)
      {
         while(list[++i] < key){}
         while(list[--j] > key){}
         if( i < j)
                swap(&list[i],&list[j]);
         else
            break;
      }
     // 交换两个元素的位置
      swap(&list[i],&list[right - 1]);
     // 递归地对较小的数据序列进行排序
      quick_sort(list,left,i-1);
      quick_sort(list,i+1,right);
   }
   else {
        insert_sort(list + left, right - left + 1);
   }
}

/*无视P183的警告的快排*/

void quick_sort(int list[],int left,int right)
{
   int key,i,j,k;
   if(left < right)
   {
      k = (left + right) / 2;
      swap(&list[left],&list[k]);
      key = list[left];
      i = left+1;
      j = right;
      while(1)
      {
         while((i < right) && (list[i] < key))
                i++;
         while((j > left) && (list[j] > key))
                j--;
         if( i < j) {
                swap(&list[i],&list[j]);
                //仅仅是为了防止死循环，见P183
                if(list[i] == list[j] && list[i] == key) {  
                    i++;  //j--;
                }
         }
         else
            break;
      }
     // 交换两个元素的位置
      swap(&list[left],&list[j]);
     // 递归地对较小的数据序列进行排序
      quick_sort(list,left,j-1);
      quick_sort(list,j+1,right);
   }
} 

