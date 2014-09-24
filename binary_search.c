int binary_search(int *a, int len, int e)
{
    int low, high, mid;
    low = 0;
    high = len - 1;
    while(low <= high) {
        mid = (low + high)/2;
        if(a[mid] == e)
            return mid;
        if else(e <= a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
