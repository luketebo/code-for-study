/**
 * @file demo_1.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 * 快速排序
 * 该方法的基本思想是：

    1．先从数数作为基列中取出一个准数。

    2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。

    3．再对左右区间重复第二步，直到各区间只有一个数。
 */
#include <iostream>
#include <vector>
using namespace std;
#define MAXSIZE 100
int select(int *arr)
{   
    

}
void divArray(int *arr, int length)
{
    int arrFirst[MAXSIZE];  // save the divide array
    int arrMedian[MAXSIZE]; // save median
    for (int i = 0; i < MAXSIZE; i++)
    {
        arrFirst[i] = 0;
        arrMedian[i] = 0;
    }
    int i;
    int m = 0;
    while (1)
    {
        for (i = 0; i < 5; i++)
        {
            arrFirst[i] = arr[i]; // get the elements
        }
        // sort
        for (int j = 0; j < i; j++)
        {
            for (int c = j; c < j; c++)
            {
                if (arrFirst[j] > arrFirst[c])
                {
                    int temp = arrFirst[j];
                    arrFirst[j] = arrFirst[c];
                    arrFirst[c] = temp;
                }
            }
        }
        for(int c : arrFirst){
            cout << c <<" ";
        }
        cout<<endl;
        if(i == 5){
            arrMedian[m++] = arrFirst[2];
        }else{
            int begin = 0;
            int end = i;
            if(i / 2 == 0){
                while( begin < end){
                    begin++;
                    end--;
                }
                arrMedian[m++] = (arrFirst[begin] + arrFirst[end]) / 2;
            }else{
               int mid = i / 2;
               arrMedian[m++] = arrFirst[mid];
            }
        }
        select(arrMedian);
    }
}
void quickSort(int *arr, int beg, int end)
{
    if (beg >= end)
    {
        return;
    }
    int first = arr[beg]; // 获取数组中第一个元素
    int i = beg;
    int j = end;
    for (int x = 0; arr[x] != NULL; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
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
        for (int x = 0; arr[x] != NULL; x++)
        {
            cout << arr[x] << " ";
        }
        cout << endl;
        arr[beg] = arr[i];
        arr[i] = first;
        quickSort(arr, beg, i - 1);
        quickSort(arr, i + 1, end);
    }
}