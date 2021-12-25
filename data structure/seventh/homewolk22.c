/***
 * 作业22：折半查找的递归算法 P232 3(1) 第七章
 * 试写出折半查找的递归算法
 * 他这种是一个算法，怎么写呢？
 * 使用最简单的数组来进行折半查找
 * 问题：
 * 怎么传递数组  
 * 使用折半查找首先需要对数据排序
 **/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
// 进行折半查找的递归算法
void Search_Arr(int arr[], int target, int left, int right)
{
   
    // 循环设置出现问题
    while (left <= right)
    {
        if (target > arr[(right - left) / 2 + left])
        {
            Search_Arr(arr, target, ((right - left) / 2 + left + 1), right);
        }
        else if (target < arr[(right - left) / 2 + left])
        {
            Search_Arr(arr, target, left, ((right - left) / 2 + left - 1));
        }
        else
        {
            printf("the target is find\n");
            printf("the element: %d the index: %d\n", arr[(right - left) / 2 + left], ((right - left) / 2 + left));
            break;
        }
        
    }
    
}
// 对数据进行排序
void Sort_Arr(int arr[])
{
    int b = 0;
    // 这个i < len - 1 and j < len - 1 - i 有什么特殊含义吗?
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}
int main()
{
    // 创建待查找的数组
    int arr[6];
    printf("please input the array numbers\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 打印
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    // 清空键盘缓冲区
    char ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        ;
    // 排序
    Sort_Arr(arr);
    //打印
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int target = 0;
    printf("please input the number you want to find\n");
    scanf("%d", &target);
    //printf("the  %d %d \n",arr[0],arr[5]);
    Search_Arr(arr, target, 0, 5);
    return 0;
}