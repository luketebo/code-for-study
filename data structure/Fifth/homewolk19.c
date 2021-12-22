/*****
 * 作业：19 计算二叉树的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值)
 * 宽度本来是指什么？那就用层次遍历
 */
#define MAXSIZE 20
// #define int width[10] = {0}
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
/*

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
*/
/*
int GetMaxWidth(BiTree pointer)
{
    // 这个数应该被赋为常数
    int width[10]; //加入这棵树的最大高度不超过10
    for (int i = 0; i < 10; i++)
    {
        width[i] = 0;
    }
    int maxWidth = 0;
    int floor = 1;
    printf("floor: %d and root: %c\n",floor,pointer->data);
    if (pointer)
    {
        if (floor == 1)
        { //如果访问的是根节点的话，第一层节点++;
            width[floor]++;
              printf("a %d %d\n",width[floor],floor);
            floor++;
            if (pointer->lchild)
                width[floor]++;
                printf("b %d %d\n",width[floor],floor);
            if (pointer->rchild)
                width[floor]++;
                printf("c %d %d\n",width[floor],floor);
        }
        else
        {
            floor++;
            if (pointer->lchild)
                width[floor]++;
            if (pointer->rchild)
                width[floor]++;
        }
        if (maxWidth < width[floor])
            maxWidth = width[floor];
        //printf("abc  %d\n", maxWidth);
        GetMaxWidth(pointer->lchild);
        floor--; //记得退回一层，否则会出错。因为已经Get过了，所以要及时的返回。
        GetMaxWidth(pointer->rchild);
    }
    return maxWidth;
}
*/
int LevelWidth(BiTree root, int level) //find the width of a level(amounts of nodes in the level).
{
    // printf("root: %c\n", root->data);
    if (!root)
        return 0;
    else
    {
        if (level == 1)
            return level;
        printf("root: %c\n", root->data);  
        level = (LevelWidth(root->lchild, level - 1) + LevelWidth(root->rchild, level - 1));
    }
    //printf("level-end: %d\n",level);
    return level;
}
int Depth(BiTree T)
{
    int rightdep = 0;
    int leftdep = 0;

    if (T == NULL)
        return -1;

    if (T->lchild != NULL)
        leftdep = Depth(T->lchild);
    else
        leftdep = -1;

    if (T->rchild != NULL)
        rightdep = Depth(T->rchild);
    else
        rightdep = -1;

    return (rightdep > leftdep) ? rightdep + 1 : leftdep + 1;
}
int Width(BiTree root) //find the maximum width of the btree.
{
    int width = 0, i;
    int w[20];
    for (i = 0; i < 20; i++)
        w[i] = 0;
    if (!root)
        width = 0;
    else
    {
        for (i = 0; i <= Depth(root); i++)
        {
            w[i] = LevelWidth(root, i + 1);
            printf("w[%d] = %d\n", i, w[i]);
        }
    }
    // printf("root depth: %d\n",Depth(root));
    i = 0;
    while (w[i])
    {
        if (w[i] > width)
        {
            width = w[i];
        }
        // printf("width: %d and w[%d]: %d\n", width, i, w[i]);
        i++;

        //printf("width: %d\n" ,width);
    }
    return width;
}
int main()
{
    BiTree t;
    CreateBiTree(&t);
    char cho;
    while ((cho = getchar()) != '\n' && cho != EOF);
    int a = Width(t);
    printf("%d", a);
}