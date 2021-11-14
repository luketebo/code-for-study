#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
    int a[3][3];
    printf("Create the array of\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int target = a[0][0];
    int i, j;
    int n = 0, m = 0;
    while (1)
    {
        for (i = 0; i < 3; i++)
        {

            for (j = 0; j < 3; j++)
            {

                if (target == a[i][j])
                {
                    if (m != i || n != j)
                    {
                        printf("%d %d %d\n", target, i, j);
                        printf("the array have the same element\n");
                        return 0;
                    }
                }
            }
        }
        n++;
        if (n == 3)
        {
            n = 0;
            m++;
        }
        if (m >= 3)
        {
            break;
        }
        target = a[m][n];
    }
    printf("the array hasn't the same element\n");
    return 0;
}