#include "binaryheap.h"
#include <assert.h>

bool is_empty(binaryheap_handle_t heap)
{
    assert(heap != NULL);
    return heap->current_size == 0;
}


bool alloc_binaryheap(binaryheap_handle_t *heap, int capacity)
{
    int *parray = NULL;

    if(*heap != NULL)
        return false;

    *heap = (int *)calloc(1, sizeof(binaryheap_t));
    if(*heap == NULL)
        return false;
    //λ��0��Ϊ��ǣ���1��Ϊ���������1��ʼ��
    parray = (int *)calloc(capacity + 1, sizeof(int));
    if(parray == NULL)
        return false;

    (*heap)->parray = parray;
    (*heap)->capacity = 0;
    (*heap)->current_size = 0;

    return true;
}


bool init_binaryheap(binaryheap_handle_t heap, int capacity)
{
    int *parray = NULL;

    if(heap == NULL)
        return false;
    parray = (int *)calloc(capacity+1, sizeof(int));
    if(parray == NULL)
        return false;

    heap->parray = parray;
    heap->capacity = capacity;
    heap->current_size = 0;

    return true;
}

//��ն��е����ݣ����ͷŷ�����ڴ棬����ɾ�������
void delete_binaryheap(binaryheap_handle_t heap)
{
    assert(heap != NULL && heap->parray != NULL);
    heap->capacity = 0;
    heap->current_size = 0;

    free(heap->parray);
    heap->parray = NULL;
}

//ɾ���ѣ��ͷ��ڴ�
void free_binaryheap(binaryheap_handle_t * heap)
{
    assert(*heap != NULL);

    (*heap)->capacity = 0;
    (*heap)->current_size = 0;

    free((*heap)->parray);
    (*heap)->parray = NULL;

    free(*heap);
    *heap = NULL;
}


/**************************************************
 * �������Ƿ�ʵ�����ݵĲ������
 * ���Ƿ���ʵ�ַ�ʽ�Ƚϼ򵥣����ȴ���һ���սڵ�
 * Ȼ����Ҫ�����ֵ�뵱ǰ��Ѩ�ĸ������бȽ�
 * ������ڸ���㣬ֱ�Ӳ����Ѩ��
 * ���С�ڸ�����ֵ���򽫸�����ֵ��������Ѩ��
 * ֮ǰ������λ�þ��ǿ�Ѩ���������ϲ�Ƚ�
 * ֱ���ҵ��������ڵ�ǰ����ֵ�����
 **************************************************/
bool insert(binaryheap_handle_t heap, int value)
{
    int index = 0;

    if(heap == NULL || heap->parray == NULL)
        return false;
    /*�õ�һ���µĿ�Ѩ�±�*/
    index = ++heap->current_size;
    /*�����ǲ��ǵ�һ���±�Ͳ���ֵ�ȶ�Ӧ�����С*/
    while(index > 1 && value < heap->parray[index/2])
    {
        /*������㱣�浽��ǰ��㴦*/
        heap->parray[index] = heap->parray[index/2];
        /*�õ������Ŀ�Ѩλ��*/
        index /= 2;
    }
    /*�������ֵ���浽ʣ��Ŀ�Ѩ��*/
    heap->parray[index] = value;

    return true;
}

/***********************************************************
 * ���Ƿ�ʵ�����ݵ����������
 * ʵ�ֵķ�ʽ�����ӽ����������ӽ��бȽϣ���С������
 * ��Ҫע�����������жϽڵ��Ƿ�һ�������Ҷ���
 * ʵ�ֵķ�ʽ��Ҫ�������˶���ѵ�����:
 * 2*pare = L_child
 * 2*pare + 1 = R_child; 
 ***********************************************************/
static void presort_binaryheap(binaryheap_handle_t heap, int hole)
{
    int child = hole * 2;
    int tmp = 0;

    assert(heap != NULL && heap->parray != NULL);
    tmp = heap->parray[hole];

    /*hold * 2 <= heap->currentSize �ж��˵�ǰ����Ƿ�Ϊ��Ͳ�*/
    for(; hole * 2 <= heap->current_size; hole = child) {
        child = hole * 2;
        /*******************************
         *���������Ƿ�����ҽ�������
         *��ȷ�����Ǹ��ӽ������������
         *******************************/
        if((child != heap->current_size) 
            && (heap->parray[child + 1] < heap->parray[child]))
            child++;
            
        if(heap->parray[child] < tmp)
        {
            /*���ӽ������Ϊ�����*/
            heap->parray[hole] = heap->parray[child];
        }
    }
    /*��������͵Ĳ㣬Ҳ������Ҷ*/
    heap->parray[hole] = tmp;
}

/*ʵ�����ݵ����Ƿ�ʵ�����ݵ�ɾ������*/
int deletemin(binaryheap_handle_t heap)
{
    int ret = 0;
    int index = 0;

    assert(!is_empty(heap));
    ret = heap->parray[1];
    /*�������Ҫ�ͷ��ڴ�ռ��ֵ���浽��һ���ڴ�ռ���*/
    heap->parray[1] = heap->parray[heap->current_size--];
    /*�ӱ�ͷ��ʼ���µĶ�����������������*/
    presort_binaryheap(heap, 1);

    return ret;
}