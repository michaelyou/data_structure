/* ���ֲ��� * �㷨˼�룺1������������(��С����)��
 * 2��ÿ�θ��м����mid�Ƚϣ������ȿ���ֱ�ӷ��أ� 
 * �����mid����������Ҵ��һ�ߣ������������С��һ�ߡ�  
 * ���룺����õ����� - sSource[]��
 *       �����С - array_size��
 *       ���ҵ�ֵ - key  
 *       ���أ��ҵ�������Ӧ��λ�ã����򷵻�-1
 */
int BinSearch(int sSource[], int array_size, int key)
{		
    int low = 0, high = array_size - 1, mid;
    
    while (low <= high)	{
        //��ȡ�м��λ�ã����ǵ��������ܴ�ʱ���������������ķ���
        //mid = (low + high) 
        mid = low + (high - low)/2  
        
        if (sSource[mid] == key)						
            return mid;	//�ҵ��򷵻���Ӧ��λ��		
        if (sSource[mid] > key)					
            high = mid - 1;	//�����key�������͵�λ�ò���	
        else			
            low = mid + 1;	//�����keyС�������ߵ�λ�ò���	
    }		
    return -1;	
}

