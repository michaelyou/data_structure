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
/*
��һ���Ѿ�������������У�Ҫ��������Ѿ��źõ����������в���һ������
��Ҫ�����������������Ȼ�������ʱ���Ҫ�õ�һ���µ����򷽷�����
��������,��������Ļ����������ǽ�һ�����ݲ��뵽�Ѿ��ź������������
�У��Ӷ��õ�һ���µġ�������һ���������ݣ��㷨�������������ݵ�����
ʱ�临�Ӷ�ΪO(n^2)�����ȶ������򷽷���
�����㷨��Ҫ���������ֳ������֣���һ���ְ�����������������Ԫ�أ�
�������һ��Ԫ�س��⣨�������һ���ռ���в����λ�ã���
���ڶ����־�ֻ������һ��Ԫ�أ���������Ԫ�أ����ڵ�һ����������ɺ�
�ٽ�������Ԫ�ز��뵽���ź���ĵ�һ�����С�
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
Shell������DL. Shell��1959�����ֱ�Ӳ��������㷨�Ľ�����ģ�
���ڲ�������ķ��룬�Ƕ�ֱ�Ӳ��������㷨�ĸĽ���
ֱ�Ӳ��������ڻ�������ʱЧ�ʽϸߣ����������й�ģ���Ǻܴ�ʱЧ��Ҳ�ܸߣ�
Shell������������������иĽ�������˼���ǣ�����������n��Ԫ�أ�
��ȡһ��С��n������h1��Ϊ��һ���������Ѵ��������Լ��h1�ֳ����������У�
��������ʹ�ò�������Ȼ��ȡ�ڶ�������h2(< h1)���ظ������Ļ��ֺ�����
ֱ����ȡ������hl = 1 (h1 > h2 > ... > hl)��

�����������ж�ô�Ӵ�����ǰ�ϴ󲽳�������ÿ�������й�ģ�����Ǻܴ�
��ֱ�Ӳ���Ч�ʺܸߣ����沽����С�������б��
����������������Խ��Խ���ԣ�����Ч����Ȼ�ܸߣ���������ʱ��Ч�ʡ�
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
         * �������ӵ�����㣬
         * ���ӽ���λ���ϴ��ڿ�Ѩ��
         * ��Ҫ�����Ƚ�
         **************************/
        if(a[child] > tmp)
                a[i] = a[child];
        else/*����Ҫ����*/
                break;
    }
    /*�������λ���ҵ�*/
    a[i] = tmp;
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
        perc_down(a, step, size);
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
        perc_down(a,0,i);
        
    }
   
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

/*�ݹ�ͷ���*/
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
      while(i < j)
      {
         while((i <= right) && (list[i] < key))
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

