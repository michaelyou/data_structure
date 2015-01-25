/* 二分查找 * 算法思想：1、将数组排序(从小到大)；
 * 2、每次跟中间的数mid比较，如果相等可以直接返回， 
 * 如果比mid大则继续查找大的一边，否则继续查找小的一边。  
 * 输入：排序好的数组 - sSource[]，
 *       数组大小 - array_size，
 *       查找的值 - key  
 *       返回：找到返回相应的位置，否则返回-1
 */
int BinSearch(int sSource[], int array_size, int key)
{		
    int low = 0, high = array_size - 1, mid;
    
    while (low <= high)	{				
        mid = (low + high) / 2;//获取中间的位置
        
        if (sSource[mid] == key)						
            return mid;	//找到则返回相应的位置		
        if (sSource[mid] > key)					
            high = mid - 1;	//如果比key大，则往低的位置查找	
        else			
            low = mid + 1;	//如果比key小，则往高的位置查找	
    }		
    return -1;	
 }

