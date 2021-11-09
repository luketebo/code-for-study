/********************
 * 线索二叉树的尝试,我只是感觉我们之前学习的数据结构非常的不严谨，
 * 完全不像一种语言，老实说，我是很讨厌这种写法的，我这样写，真的对吗？
 * 我还是老老实实用c来写吧，不要用c++来写了，那样写的一点都不好
 * */
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
//线索存储标志位
//link(0) 表示指向左右孩子的指针
//thread(1) 表示指向前驱后继的线索
//全局变量，始终指向刚刚访问过的节点
#define BiThrTree pre;
//这种写法没用过
typedef enum
{
    Link,   
    Thread
} pointerTag;
typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    pointerTag ltag;
    pointerTag rtag;
} BiThrNode, *BiThrTree;
//创建一个带线索的二叉树
void CreateBiThrTree(BiThrNode *T)
{
    char c;
    scanf("%c", &c);
    if (' ' == c)
    {
        T = NULL;
    }
    else
    {
        T = (BiThrNode *)malloc(sizeof(BiThrNode));
        T->data = c;
        T->ltag = Link;
        T->rtag = Link;

        CreateBiThrTree(&(T->lchild));
        CreateBiThrTree(&(T->rchild));
    }
}
//中序遍历线索化
/*
void InThreading(BiThrTree *T)
{
    if (T)
    {
        Inthreading(T->lchild); //递归左孩子线索化

        //结点处理
        if (!T->lchild)      //如果该节点没有左孩子，设置ltag为thread ，并把lchild指向上一个访问的结点
        {
            T->ltag = Thread; 
            T->lchild = pre;
        }
        if(!pre->rchild){
            pre->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;

        InThreading(T->rchild); //递归右孩子处理线索化
    }
}   
*/
void InorderThreading(BiThrTree *p,BiThrTree *T)
{
    *p = (BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if(!T){
        (*p)->lchild = *p;
    }else {
        (*p)->lchild = T;
        pre = *p;

        InThreading(T);
    }
    pre->rchild = *p;
    pre->rtag = Thread;
    (*p)->rchild = pre;
}

int main(){

    BiThrTree T = NULL;
    CreateBiThrTree(&T);
    InOrderThreading(&p,T);
    return 0;
}