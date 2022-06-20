/**
 * @file BFS.cpp
 * @author Luke Tebo (luketebo.ycs@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-07
 * 
 * @copyright Copyright (c) 2022
 * 
 * BFS: 单源最短路劲问题
 */
#include <stdio.h>

int main()
{
    int i, j, m, n;
    int q1, q2, q3;
    int u, v, min;
    int e[100][100], dis[10], book[10];
    int inf = 99999999;//用inf表示我们认为的无穷值

    scanf("%d %d", &n, &m);//读入n，m，n表示顶点个数，m表示边的条数
    //初始化
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = inf;
            }
        }
    }

    //读入边
    for (i = 1; i <= m; ++i)
    {
        scanf("%d %d %d", &q1, &q2, &q3);
        e[q1][q2] = q3;//有向图
    }

    //初始化dis数组，这里是1号顶点到其余各顶点的初始路程
    for (i = 1; i <= n; ++i)
    {
        dis[i] = e[1][i];
    }

    //book、数组初始化
    for (i = 1; i <= n; i++)
        book[i] = 0;
    book[1] = 1;         
    // Dijkstra 算法核心
    for (i = 1; i < n; ++i)      // 计算n-1次
    {
        //找到离1号顶点最近的顶点
        min = inf;
        for (j = 1; j <= n; ++j)
        {
            if (dis[j] < min && book[j] == 0)
            {
                min = dis[j];
                u = j;  //u为最近的点
            }
        }
        book[u] = 1;

        //对u的所有出边进行“松弛”
        for (v = 1; v <= n; ++v)
        {
            if (e[u][v] != inf && dis[v] > dis[u] + e[u][v])
            {
                dis[v] = dis[u] + e[u][v];            //这个过程就是"松弛"
            }
        }
    }

    printf("结果为：\n");
    //输出最终的结果
    for (i = 1; i <= n; ++i)
    {
        printf(" 1号顶点到%d号顶点的最短距离为：%d\n",i, dis[i]);
    }
    printf("\n");

    getchar();
    getchar();
    return 0;
}