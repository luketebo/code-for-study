/**作业14：设一个二维数组，有m*n个整数，写一个算法判断a中所有的元素是否互不相同，输出相关信息
 * 试分析算法的时间复杂度
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[10][10];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", a[i][j]);
        }
    }
    //进行比较
    //使用这种想法，直接选一个值，和后面的比较，有相同的就返回，没有就不返回

    int j, i;
    int target = a[0][0]; //定义一个量，去和二维数组中的元素进行比较
    while (1)
    {
        //这个for循环走完才算是把第一次的数据比对完成。
        for (i = 0; i < 10; i++)
        {

            for (j = 10 - i; j < 10; j++)
            {
                if (target == a[i][j])
                {
                    printf("二维数组中有元素相同\n");
                    return 0;
                }
            }
        }
        
    }
    return 0;
}