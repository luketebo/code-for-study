#include <stdio.h>
//实现分割操作的函数
void merge_sort(int* arr, int p, int q);
//实现归并操作的函数
void merge(int* arr, int p, int mid, int q);

int main() {
    int i = 0;
    // int arr[8] = { 7,5,2,4,1,6,3,0 };
    int arr[8] = {3, 5, 6, 8, 1, 2, 4, 0};
    //对 arr 数组中第 1 至 8 个元素进行归并排序
    merge_sort(arr, 1, 8);
    while (i < 8)
    {
        printf("%d ", arr[i]);
        i++;
    }
    return 0;
}
//实现分割操作的函数，[p,q] 用于指定归并排序的区域范围，
void merge_sort(int* arr, int p, int q) {
    int mid;
    if (arr == NULL || p > q || p == q) {
        return ;
    }
    mid = (p + q) / 2;
    //将 [p,q] 分为[p,mid] 和 [mid+1,q] 区域
    merge_sort(arr, p, mid);
    merge_sort(arr, mid + 1, q);
    //对分好的 [p,mid] 和 [mid,q] 进行归并操作
    merge(arr, p, mid, q);
}
//实现归并操作的函数，归并的 2 个区域分别为 [p,mid] 和 [mid+1,q]
void merge(int* arr, int p, int mid, int q) {
    int i,j,k;
    int leftarr[100], rightarr[100];
    int numL = mid - p + 1;
    int numR = q - mid;
    //将 arr 数组中 [p,mid] 区域内的元素逐一拷贝到 leftarr 数组中
    for (i = 0; i < numL; i++) {
        leftarr[i] = arr[p - 1 + i];
    }
    //将 arr 数组中 [mid+1,q] 区域内的元素逐一拷贝到 rightarr 数组中
    leftarr[i] = 2147483647;
    for (i = 0; i < numR; i++) {
        rightarr[i] = arr[mid + i];
    }
    rightarr[i] = 2147483647;
    i = 0;
    j = 0;
    //逐一比较 leftarr 和 rightarr 中的元素，每次将较小的元素拷贝到 arr 数组中的 [p,q] 区域内
    for (k = p; k <= q; k++) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k - 1] = leftarr[i];
            i++;
        }
        else {
            arr[k - 1] = rightarr[j];
            j++;
        }
    }
}