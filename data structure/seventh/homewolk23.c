/***
 * 判别二叉树排序树 p232 3(2) 第七章
 * 试写一个判别给定二叉树是否为二叉排序树的算法
 * 判断条件：
 * 1.判断条件：左 < 中 < 右
 * 2.递归判断左右子树
 * 3.递归结束条件：该结点为叶子结点
 * 我总感觉我自己写的打印方法不是特别科学
 * ab#d##c##
 * ad#b##c##
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
typedef char ElemType;
//创建二叉树
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
// 创建二叉树 前序遍历
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
        *T = (BiNode *)malloc(sizeof(BiNode)); // 创建一个结点
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
void func(char node)
{

    printf("%c ", node);
}
// 打印二叉树
void Print_BiTree(BiTree T)
{
    if (T != NULL)
    {
        func(T->data);
        Print_BiTree(T->lchild);
        Print_BiTree(T->rchild);
    }
}
// 判断二叉树是否为二叉排序树
/*
 * 判断条件：
 * 1.判断条件：左 < 中 < 右
 * 2.递归判断左右子树
 * 3.递归结束条件：该结点为叶子结点
*/
bool Judge_BiTree(BiTree tree)
{

    if (!tree) // 树为空树
        return true;
    BiTree lChildD = tree->lchild;
    BiTree rChildD = tree->rchild;
    //判断是否满足二叉排序树的特点：左<中<右
    if ((lChildD && (lChildD->data > tree->data)) || (rChildD && (rChildD->data < tree->data)))
    {
        return false;
    }
    else if (!lChildD || !rChildD)
    { //为叶子结点的情况
        return true;
    }
    else
    { //递归判断左右子树
        //printf("%d %d %d\n",tree->data,lChildD->data,rChildD->data);
        return Judge_BiTree(tree->lchild) && Judge_BiTree(tree->rchild);
    }
}
int main()
{
    BiTree p = NULL;
    CreateBiTree(&p);
    Print_BiTree(p);
    printf("\n");
    bool flag = true;
    flag = Judge_BiTree(p);
    if (flag)
    {
        printf("the tree is 二叉排序树\n");
        return 0;
    }
    else
    {
        printf("the tree is not 二叉排序树\n");
        return 0;
    }
}