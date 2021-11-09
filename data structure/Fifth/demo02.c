/**
 * 二叉树的第二次尝试
 * 用最基本的二叉树?,关键是我写不来c语言呀，太久没用了
 * 啥指针都忘得差不多了，随便吧，用什么语言
 * 先想好，我要用什么语言来写数据结构，我是否是真的受不了
 * c++来写数据结构,我照着他写的但是我写的有问题，运行不了，为啥子?
 * 
 * 
 * 已经被我创建，现在只有编码问题了，第一个写完了 
 * */
#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
//创建一个二叉树,预定用户用前序遍历的方式输入数据
void CreateBiTree(BiTree *T)
{ //需要一个指�?
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiNode *)malloc(sizeof(BiNode)); //创建一个新的（结点）？

        (*T)->data = ch;
        //指针好像没有平衡
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
//访问二叉树的具体操作
void visit(char c,int level)
{
    printf("%c λ�� %d ��\n",c,level);
}
//遍历二叉�? 前序遍历
void PreOrder(BiTree T, int level)
{
    if (T)
    {
        visit(T->data, level);          //D
        PreOrder(T->lchild, level + 1); //L
        PreOrder(T->rchild, level + 1); //R
    }
}
int main(void)
{
    int level = 0;
    BiTree T = NULL;            //     T是一个指针，那我传递的是指针的地址
    CreateBiTree(&T);
    PreOrder(T,level);
    return 0;
}