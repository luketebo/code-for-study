/**
 * 编写算法，实现字符串的插入操作，给s分配足够的空间，让t随便插入,给s一个pos然后插入
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void insert(char *s, char *t, int pos)
{
    printf("insert\n");
    int t_len = strlen(t);
    int s_len = strlen(s);
    //移动pos后面的元素
    for (int i = s_len; i >= pos; i--)
    {
        s[i + t_len] = s[i];
    }
    int n = 0;
    for(int i=pos;i< pos+t_len;i++)
    {
        s[i] = t[n++];

    }
     for (int i = 0; i < s_len + t_len; i++)
    {
        printf(" %c ", s[i]);
    }
}
int main()
{
    char a[100];
    char b[10];
    int pos = 0;
    //我没有加&这个符号，但是为啥子程序连print都没有执行呢？啥子原因？
    printf("please input the array values of a:\n");
    scanf("%s", &a);
    printf("please input the array values of b:\n");
    scanf("%s", &b);
    printf("please input the pos:\n");
    scanf("%d", &pos);
    //上面执行完了之后，就直接结束程序了，为啥呀
    //为什么没有做这个呢？
    //   printf("bad");
    insert(&a, &b, pos);
    //   printf("good");
}