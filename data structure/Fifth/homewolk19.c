/*****
 * 作业：19 计算二叉树的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值)
 * 宽度本来是指什么？那就用层次遍历
 */
#define MAXSIZE 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ElemType;
//创建二叉树
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
//  创建队列
typedef struct
{
    int front;
    int rear;
    BiTree *base;
} Queue;
//  初始化队列
int InitQueue(Queue Q)
{
    Q.base = (BiNode *)malloc(sizeof(BiNode) * MAXSIZE);
    if (!Q.base)
        exit;
    Q.front = Q.rear;
    return 1;
}
//  判断队列是否为空
int EmptyQueue(Queue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}
//  进队
int EnQueue(Queue Q, BiTree e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return 0;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return 1;
}
//  出队
int DeQueue(Queue Q, BiTree e)
{
    if (Q.front == Q.rear)
        return 0;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return 1;
}
// 创建一颗二叉树
void CreateBiTree(BiTree *T)
{
    char ch = NULL;
    scanf("%c", &ch);
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
// 层次遍历
void LevOrder(BiTree T)
{
    Queue Q;
    BiTree e;
    InitQueue(Q);
    EnQueue(Q,T);   //这样进队有毛病
    printf("%c ",T->data);
    int a = 0;
    while (a == EmptyQueue(Q))
    {
        DeQueue(Q,e);
        printf("%c ",e->data);
        if(e->lchild){
            EnQueue(Q,e->lchild);
        }
        if(e->rchild){
            EnQueue(Q,e->rchild);
        }
    }
}
int main()
{
    BiTree t;
    CreateBiTree(&t);
    LevOrder(&t);
}