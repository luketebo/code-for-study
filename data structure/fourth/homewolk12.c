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
        printf("%d ", as[i]);
    }
    
    //写入文件,很简单，这要写入两个数组就可以直接使用了，第一个数组是符合条件的字符
    //第二个数据就是得到的数据了
    //进行写操作,写成功了，但是读取有问题
    
    printf("\n");
    FILE *fpwrite = fopen("test.txt", "w");
    if (fpwrite == NULL)
    {
        return 0;
    }
    for (int i = 0; i < 36; i++)
    {
        fprintf(fpwrite, "%d ", as[i]);
    }
    fclose(fpwrite);
    
    //进行读操作
    int ab[36] = {0};
    char a[37] = {0};
    FILE *fpread = fopen("test.txt", "r");
    if (fpread == NULL)
    {
        return 0;
    }
    for (int i = 0; i < 36; i++)
    {
        //空格真jb叼
        
        fscanf(fpread, "%d", &ab[i]);     //为啥子第一个值要不能正常读取；缓冲区没有清理
      //  while ((ab[i] = getchar()) != EOF && ab[i] != '\n') ;
        printf("%d ", ab[i]);
    }
    /*
    for(int i = 0; i < 36; i++){
        printf("%d ", ax[i]);
    }
    */
    fclose(fpread);
    //  getchar();
    /*
    printf("\n");
    for (int i = 0; i < 36; i++)
    {
        printf(" %d ", as[i]);
    }*/

    return 0;
}