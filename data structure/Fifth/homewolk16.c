#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
//创建一棵二叉树,tmd 为撒子跳不出去，我日，马勒戈壁
void CreateBiTree(BiTree *T)
{
    char ch;

   // printf("Creating");

    scanf("%c", &ch);
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        // printf("CreateBiTree");
        *T = (BiNode *)malloc(sizeof(BiNode)); //创建一个新的结点
        (*T)->data = ch;                       //中间的根结点
        //现在就做输入左子树
        CreateBiTree(&(*T)->lchild); //这里面应该是一个指针，或者是一个地址
        //输入右子树
        CreateBiTree(&(*T)->rchild);
    }
}
//实现功能
void fuction(int num)
{
    printf("结点数: %d \n ", num);
}
//二叉树的前序遍历，寻找结点?
void PreOrder(BiTree T, int num)
{ //为什么遍历的时候，要传递指针，传值理论上应该也是可以的吧
   // printf("bc");
    if (T)
    {
        //写一个函数实现功能
        fuction(num);
        //左子树
        PreOrder(T->lchild, num + 1);
        //右子树
        PreOrder(T->rchild, num + 1);
    }
}

int main()
{
    BiTree T = NULL;
    int num = 0;
   // printf("akfnlkjsfglka");
    CreateBiTree(&T);
    PreOrder(T, num);
 //   printf("cc");
    return 0;
}