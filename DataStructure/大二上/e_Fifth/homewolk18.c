/**作业：18 交换二叉树结点的左孩子和右孩子
 * 我有点点搞不懂这个循环递归的操作，还是太高大上了，直呼太难
 * 我还不如自己想一个创建二叉树的方法，他那么创建，实在是太强了
 * 案例 ab##c##
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef char ElemType;
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
//创建二叉树  真的很神奇
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
void func(char t)
{

    printf("%c", t);
}
// 遍历二叉树
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        //进行工作的函数，交换孩子？
        func(T->data);

        PreOrder(T->lchild);

        PreOrder(T->rchild);
    }
}
void Change(BiTree T)
{
    BiTree temp;
    if (T->lchild == NULL && T->rchild == NULL)
        return;
    else{
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }// 交换左右孩子？
    Change(T->lchild);
    Change(T->rchild);
}

int main(void)
{
    BiTree T = NULL;
    CreateBiTree(&T);
    PreOrder(T);
    Change(T);
    printf("\n");
    PreOrder(T);
    return 0;
}