/**
 * @file quickSort.c++
 * @author Luke Tebo(you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-29
 *
 * @copyright Copyright (c) 2022
 *
 * 快速排序
 * 该方法的基本思想是：

    1．先从数列中取出一个数作为基准数。

    2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。

    3．再对左右区间重复第二步，直到各区间只有一个数。
 */
#include <iostream>
using namespace std;
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        // Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];

            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}
void QuickSort(int *arr, int beg, int end)
{
    if (beg > end)
    {
        return;
    }
    int first = arr[beg]; // 获取数组中第一个元素
    int i = beg;
    int j = end;
    // for(int x = 0; arr[x] != NULL; x++){
    //         cout<<arr[x]<<" ";
    // }
    // cout<<endl;
    while (i != j)
    {
        while (arr[j] >= first && i < j)
        {
            j--;
        }
        while (arr[i] <= first && i < j)
        {
            i++;
        }

        if (j > i)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        // for(int x = 0; arr[x] != NULL; x++){
        //     cout<<arr[x]<<" ";
        // }
        //     for(int c : arr){
        //       cout<<c<<" ";
        // }
        // cout<<endl;
        arr[beg] = arr[i];
        arr[i] = first;
        QuickSort(arr, beg, i - 1);
        QuickSort(arr, i + 1, end);
    }
}
int main()
{
    // int arr[10];
    // cout << "please input the array" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> arr[i];
    // }
    int arr[10] = {4, 5, 6, 8, 3, 2, 9, 0, 1, 7};
    // int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int c : arr)
    {
        cout << c << " ";
    }
    // for (int c : arr)
    // {
    //     cout << c << " ";
    // }
    cout << endl;
    // QuickSort(arr, 0, 9);
    quick_sort(arr, 0, 9);
    for (int c : arr)
    {
        cout << c << " ";
    }
    cout << endl;
}