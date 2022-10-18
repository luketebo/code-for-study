#include <iostream>
using namespace std;
#define MAX 100

#ifndef MERGE_H
#define MERGE_H
class MERGE
{
public:
    // // 进行分割
    // void merge_sort(int *arr, int beg, int end);
    // // 进行合并
    // void merge(int *arr, int beg, int mid, int end);
    int main()
    {
        // int arr[8] = {3, 5, 6, 8, 1, 2, 4, 0};
        cout << "算法简介" << endl;
        cout << "1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列\n2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置；\n3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；\n4. 重复步骤 3 直到某一指针达到序列尾；\n5. 将另一序列剩下的所有元素直接复制到合并序列尾。" << endl;
        int arr[MAX];
        int count = 0;
        cout << "input the array's length: ";
        cin >> count;
        cout << "input the array: ";
        for (int i = 0; i < count; i++)
        {
            cin >> arr[i];
        }
        cout << "归并排序" << endl;
        merge_sort(arr, 1, count);
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        
        return 0;
    }
    void print(int arr[], int beg, int end){
        cout << endl;
        for (int i = beg; i < end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
        cout << "分割点: " << mid << endl;
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
        cout << "合并操作 " << endl;
        for (k = beg; k <= end; k++) {
            cout << arr[k - 1] << " ";
        }
        cout << endl;
        cout << endl;
    }
};
#endif