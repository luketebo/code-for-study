/**
 * 作业15 一个数组有n个整数，编写算法，将所有正数排在所有负数前面，且时间复杂度为O(n)
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
    int a[100];
    printf("please input the array\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
   
  //  printf("\n");
    //冒泡法排序，什么叫做时间复杂度为n，就是执行一次就可成功
    int b = 0 , t = 0;
    for(int i =0;i<5;i++){
        if(a[i] >= 0) {
            t = a[b];
            a[b] = a[i];
            a[i] = t;
            b++;
        }
    }
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
}