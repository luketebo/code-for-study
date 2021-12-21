/***
 * 作业21：图的非递归深度优先遍历,
 * 一个连通图采用邻接矩阵作为存储结构，设计一个算法，实现从顶点v出发的深度优先遍历的非递归过程
 * DFS 算法
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MVNum 100
typedef char VerType;
typedef struct ArcNode
{ // 边结点
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;           // 存放边的信息
typedef struct VNode // 存放顶点
{                    //顶点信息
    VerType data;
    ArcNode *firstarc;   // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum]; // AdjList 表示邻接表类型
typedef struct
{ // 邻接表
    AdjList vertices;
    int vexnum, arcnum; // 图当前顶点数和边数
} ALGraph;
// 返回这个邻接表的
int LocateVex(ALGraph *G, char v)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (v == G->vertices[i].data)
        {
            return i;
        }
    }
    return -1;
}
// 用邻接表表示法创建无向图
void CreateUDG(ALGraph *G)
{
    char v1, v2;
    printf("please input the vexnum and arcnum");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    //输入顶点，构造顶点表
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    // 输入各边，构造邻接表
    for (int k = 0; k < G->arcnum; k++)
    {
        scanf("%c %c", &v1, &v2);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i == -1 || j == -1)
        {
            printf("the vexnum is wrong\n");
            exit(0);
        }
        // 创建一个新的边界点 进行数据交换
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = i;
        p1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p1;
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = j;
        p2->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = p2;
    }
    return;
}
// 深度优先遍历 DFS
void DFS_AL(ALGraph *G, int v)
{
    // 图G 为邻接表类型，从n个顶点出发深度优先遍历图G
    bool visit[MVNum]; //  通过stdbool.h 引用
    printf("%d\n", v);
    visit[v] = true;
    // 创建一个结点
    ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
    p = G->vertices[v].firstarc;
    while (p != NULL)
    {
        //  ArcNode *w = (ArcNode *)malloc(sizeof(ArcNode)); // w is v 邻接点
        int w = p->adjvex;
        if (!visit[w])
            DFS_AL(G, w);
        p = p->nextarc;
    }
}
int main(){
    
}
