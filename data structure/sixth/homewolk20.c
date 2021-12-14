/**
 * 作业 20： 利用邻接矩阵实现图的基本操作
 * 1.增加一个新顶点v，insert(G,V)
 * 2.删除顶点v以及相关的边，DeleteVex(G,V)
 * 3.增加一条边<v,w> InsertArc(G,v,w)
 * 4.删除一条边<v,w> DeleteArc(G,v,w)
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
typedef char ElemType;
//创建邻接矩阵  我这个应该叫邻接链表
typedef struct {
    struct tu * front , * tail;
    ElemType info;
}tu;
// 点
typedef struct {
    ElemType data; //数组？
    tu * next;
}Adjacency;   //邻接
*/
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum;         //图的当前点数和边数
} AMGraph, *graph;
int Locate(AMGraph *t, char a)
{
    for (int i = 0; i < t->vexnum; i++)
    {
        if (a == t->vexs[i])
        {
            return i;
        }
    }
}
//创建图
void CreateGraph(AMGraph *t)
{
    char ch = 0;
    printf("input the all vertex and the side\n");
    scanf("%d %d", &t->vexnum, &t->arcnum);
    while ((ch = getchar()) != EOF && ch != '\n');
    printf("input the all vertex\n");
    for (int i = 0; i < t->vexnum; i++)
    {
        scanf("%c", &t->vexs[i]);
    }
    while ((ch = getchar()) != EOF && ch != '\n');   //清除键盘缓冲区

    for(int i = 0; i < t->vexnum; i++){
        printf("good %c good\n",t->vexs[i]);
    }
   
    for (int i = 0; i < t->arcnum; i++)
    {
        for (int j = 0; j < t->arcnum; j++)
        {
            t->arcs[i][j] = MaxInt;
        }
    }
    //对邻接矩阵中的值进行修改
    int weight = 0;
    char v1 = 0;
    char v2 = 0;
    for (int k = 0; k < t->arcnum; k++)
    {
        printf("please the side for vertex and weight\n");
        scanf("%c %c %d", &v1, &v2, &weight);
        int i = Locate(t, v1);
        int j = Locate(t, v2);
        printf("%d %d\n", i, j);
        t->arcs[i][j] = weight;
        while ((ch = getchar()) != EOF && ch != '\n')
            ;
    }
    return;
}
//1.增加一个新顶点v，insert(G,V)
void insert(AMGraph *t, int v)
{
    //增加了顶点那就要修改部分边的关系
    if (t->vexnum + 1 > MVNum)
    {
        printf("the picture is full\n");
        exit(0);
    }
    t->vexnum++;
    t->vexs[t->vexnum + 1] = v;
    int weight = 0;
    for (int i = 0; i < (t->vexnum + 1); i++)
    {
        printf("please input the %c and %c and weight\n", t->vexs[i], v);
        scanf("%d", &t->arcs[i][t->vexnum + 1]);
    }
}
//2.删除顶点v以及相关的边，DeleteVex(G,V)
void DeleteVex(AMGraph *t, int v)
{
}
//3.增加一条边<v,w> InsertArc(G,v,w)
void InsertArc(AMGraph *t, int weight, int v)
{
}
//4.删除一条边<v,w> DeleteArc(G,v,w)
void DeleteArc(AMGraph *t, int v, int weight)
{
}
//5.分开显示该图的顶点表和邻接矩阵表
void Display(AMGraph *t)
{
    printf("now will display the table\n");
    printf("the vexs\n");
    for (int i = 0; i < t->vexnum; i++)
    {
        printf("%c ", t->vexs[i]);
    }
    printf("the arcs\n");
    for (int i = 0; i < t->arcnum; i++)
    {
        for (int j = 0; j < t->arcnum; j++)
        {
            printf("%d ", t->arcs[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    AMGraph t;
    CreateGraph(&t);
    Display(&t);
    /*
    char d;
    printf("please input the the insert vex\n");
    scanf("%c", &d);
    insert(&t, d);
    Display(&t);
    */
   return 0;
}