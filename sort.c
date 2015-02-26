#define elementtype int

/*�����㷨���ȶ���:ԭ����ֵһ����Ԫ����������λ�ò���*/

//ð����������Ϊ�������ų����򣬴�ʱ�ȽϽ�������Ϊn*(n-1)/2��ʱ��
//���Ӷ�ΪO(n^2)
void bubble_sort(elementtype *array, int n) {
    elementtype tmp;
    int i = 0, j = 0;
    for(; i < n - 1; i++) {
        for(j = n -1; j > i; j--) {
            if(array[j] < array[j - 1]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}


//ѡ������
//ѡ�������Ǻ�ð���������һ�����򡣺�ð�����򽻻��������ݲ�һ��
//���ǣ�ѡ������ֻ����ȷ������С������֮�󣬲Żᷢ������
/*ѡ�������ʱ�临�Ӷ�ΪO(n^2),�ǲ��ȶ��������㷨����������Ϊ5,5,3��
��һ�ξͻὫ��һ��5��3������*/
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
            tmp = array[i];
            array[i] = array[index];
            array[index] = tmp;
        }
    }
}


//��������
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
         * �������ӵ�����㣬
         * ���ӽ���λ���ϴ��ڿ�Ѩ��
         * ��Ҫ�����Ƚ�
         **************************/
        if(a[child] > tmp)
                a[index] = a[child];
        else/*����Ҫ����*/
                break;
    }
    /*�������λ���ҵ�*/
    a[index] = tmp;
}

void build_maxheap(int *a, int size)
{
    int step = 0;

    /***************************************
     * (size-1)/2ʵ�����ҵ�a[size-1]�ĸ���㣬
     * Ҳ���ǵ����ڶ��㣬�ѵĴ���������һ��
     * �ɵͲ㵽�߲��𽥴����Ĺ���
     **************************************/
    for(step = (size - 1) / 2 ; step >= 0; -- step)
        max_heapify(a, step, size);
}

void heap_sort(int *a, int size)
{
    int i = 0;
    /*������*/
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
        /*���¶ѵĽṹ*/
        max_heapify(a,0,i);
        
        
        
        //printf("%d ", a[17]);
        //printf("\n");
    }
    for(; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/**********************************************/
//�鲢����

void merge_sort(int * a, int left, int right)
{
    int i = 0;
    int *atmp = NULL;
    int *Actr = NULL, *Bctr = NULL, *Cctr = NULL;

    /*�ݹ��˳�����*/
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

/*******************��������***********************/
/*���ݽ���*/
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
     // ��������Ԫ�ص�λ��
      swap(&list[left],&list[j]);
     // �ݹ�ضԽ�С���������н�������
      quick_sort(list,left,j-1);
      quick_sort(list,j+1,right);
   }
}

