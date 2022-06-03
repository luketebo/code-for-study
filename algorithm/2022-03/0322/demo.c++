#include <iostream>
using namespace std;
// 进行分割
void merge_sort(int *arr, int beg, int end);
// 进行合并
void merge(int *arr, int beg, int mid, int end);
int main()
{
     int arr[8] = {3, 5, 6, 8, 1, 2, 4, 0};
    merge_sort(arr, 1, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}
void merge_sort(int *arr, int beg, int end)
{
    // 判断分割结束
    if (arr == NULL || beg >= end)
    {
        return;
    }
    int mid = beg + (end - beg) / 2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid + 1, end);
    // 进行合并
    merge(arr, beg, mid, end);
}
// 进行归并的分为两个区，beg -> mid , mid + 1 -> end
void merge(int *arr, int beg, int mid, int end)
{
    // 定义两个数组，用于存放两个区
    int leftarr[100], rightarr[100];
    // 左右新区间的长度, 不是简单的mid - beg
    int numL = mid - beg + 1;
    int numR = end - mid;
    int i, j;
    //将arr数组中的值，给新创建的两个区，进行赋值
    for (i = 0; i < numL; i++)
    {
        // 区间的长度
        leftarr[i] = arr[beg - 1 + i];
    }
    leftarr[i] = 2147483647; // 32位操作系统中最大的符号型整形常量
    for (i = 0; i < numR; i++)
    {
        rightarr[i] = arr[mid + i];
    }
    rightarr[i] = 2147483647;
    i = 0;
    j = 0;
    int k;
    // 合并操作 比较leftarr 和 rightarr中的元素，将晓得拷贝给原arr区
    for (k = beg; k <= end; k++)
    {
        // 设置两个参数，然后以不同方式递增
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