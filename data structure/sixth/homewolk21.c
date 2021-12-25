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
            printf("i: %d\n", i);
            return i;
        }
    }
    printf("%c\n", v);
    return -1;
}
// 用邻接表表示法创建无向图
void CreateUDG(ALGraph *G)
{
    char v1, v2;
    printf("please input the vexnum and arcnum\n");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    char ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        ;
    //输入顶点，构造顶点表
    printf("please input the vexnum 顶点\n");
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    while ((ch = getchar()) != EOF && ch != '\n')
        ;
    // 忘了c语言一个很重要的东西，那就是清除键盘缓冲区

    // 输入各边，构造邻接表
    printf("please input the arcnum 边\n");
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
        /**
         * 注意这两个坐标的变化，(p1)我修改了第一个 j 之前是 i
         * 还有第二个i 之前是j （p2）
         */
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j;
        p1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p1;
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = i;
        p2->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = p2;
        // 每一次都需要清除键盘缓冲区，c语言有一点点麻烦呀
        while ((ch = getchar()) != EOF && ch != '\n')
            ;
    }
    return;
}
// 打印邻接表
void Print_AL(ALGraph *G)
{
    int i;
    ArcNode *p;
    printf("图的邻接表\n");

    for (i = 0; i < G->vexnum; i++)
    {
        printf("\n  AdjList[%d]%4c", i, G->vertices[i].data);

        p = G->vertices[i].firstarc;

        while (p != NULL)
        {
            printf("-->%d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}
bool visit[MVNum]; //  通过stdbool.h 引用
// 深度优先遍历 DFS
void DFS_AL(ALGraph *G, int v)
{
    // 图G 为邻接表类型，从n个顶点出发深度优先遍历图G
    // 深度遍历只有我需要打印出来
    printf("%c", G->vertices[v].data);
    visit[v] = true;
    // 创建一个结点
    ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
    p = G->vertices[v].firstarc;
    while (p != NULL)
    {
        //  ArcNode *w = (ArcNode *)malloc(sizeof(ArcNode)); // w is v 邻接点
        int w = p->adjvex; // 这一句有点点问题，w是v的邻接点
        if (!visit[w])
            DFS_AL(G, w);
        p = p->nextarc;
    }
}
// 打印深度遍历
void DFSTraverse(ALGraph *G){
    int i;
    for(int i = 0; i < G->vexnum;i++){
        visit[i] = true;
    }
    for(int i = 0; i < G->vexnum; i++){
        if(visit[i]){
            DFS_AL(G,i);
        }
    }
}
int main()
{
    ALGraph G;
    CreateUDG(&G);
    int v = 0;
   // printf("please input the number you want to visit first\n");
   // scanf("%d", &v);
    Print_AL(&G);
    printf("\n\n深度优先遍历："); 
    DFSTraverse(&G);

    return 0;
}
