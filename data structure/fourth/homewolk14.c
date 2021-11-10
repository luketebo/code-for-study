/**作业14：设一个二维数组，有m*n个整数，写一个算法判断a中所有的元素是否互不相同，输出相关信息
 * 试分析算法的时间复杂度
 * 当我走向一维数组的时候，一切都已经没有了意义
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    //进行比较
    int temp = a[0];
    for (int j = 0; j < 10; j++)
    {
        temp = a[j];
        for (int i = j + 1; i < 10; i++)
        {
            if (temp == a[i])
            {
                printf("数组中有相同的元素\n");
                return 0;
            }
        }
    }
    printf("数组中没有相同的元素\n");
    return 0;
}