/**
 * 作业12：字符频度统计
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
    char ac[100];
    int as[36];
    //初始化
    for (int i = 0; i < 36; i++)
    {
        as[i] = 0;
    }
    printf("please input the array of ac values\n");
    scanf("%s", ac);
    int ac_len = strlen(ac);

    for (int i = 0; i < ac_len; i++)
    {
        if (ac[i] >= 'A' && ac[i] <= 'Z')
        {
            int vb = ac[i] - 'A';

            as[vb + 10]++;
        }
        if (ac[i] >= '0' && ac[i] <= '9')
        {
            int va = ac[i] - '0';
            as[va]++;
        }
    }

    for (int i = 0; i < 36; i++)
    {
        printf(" %d ", as[i]);
    }

    //写入文件
    

    return 0;
}