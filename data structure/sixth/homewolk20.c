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
typedef char ElemType;
//创建邻接矩阵
typedef struct {
    struct tu * front , * tail;
    ElemType info;
}tu;
// 点
typedef struct {
    ElemType data; //数组？
    tu * next;
}Adjacency;