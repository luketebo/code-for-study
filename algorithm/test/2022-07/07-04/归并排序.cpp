#include <iostream>
using namespace std;
void merge(int *arr, int beg, int mid, int end)
{
    int leftarr[100], rightarr[100];
    int numL = mid - beg + 1;
    int numR = end - mid;
    int i, j;
    for (i = 0; i < numL; i++ )
    {
        leftarr[i] = arr[beg - 1 + i];
    }
    leftarr[i] = INT32_MAX;
    for (i = 0; i < numR; i++) {
        rightarr[i] = arr[mid + 1];
    }
    rightarr[i] = INT32_MAX;
    i = 0;
    j = 0;
    int k;
    for (k = beg; k <= end; k++)
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k - 1] = leftarr[i];
            i++;
        }
        else 
        {
            arr[k - 1] = rightarr[j];
            j++;
        }
    }
}
void merge_sort(int *arr, int beg, int end){
    if (arr == NULL || beg >= end)
    {
        return;
    }
    int mid = beg + (end - beg) / 2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
}
int main() {

    return 0;
}