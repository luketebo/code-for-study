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
    printf("please input the array values of a:\n");
    scanf("%s", &a);
    printf("please input the array values of b:\n");
    scanf("%s", &b);
    printf("please input the pos:\n");
    scanf("%d", &pos);
    insert(&a, &b, pos);
}