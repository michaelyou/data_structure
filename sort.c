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

