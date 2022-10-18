/***
 * 二叉排序树的查找 p232 3(3) 第七章
 * 已知二叉排序树采用二叉链表存储结构，根结点的指针为T,链接点的数据结构为（Lchild,data,rchild)
 * 其中lchild rchild 分别指向该结点左右孩子的指针，data域存放结点的数据信息，请写出递归算法，从小到大
 * 输出二叉排序树中所有数据值 >= x 的结点的数据，要求先找到第一个满足条件的节点后，在一次输出其他满足
 * 条件的结点
 * 
 * x 没有定义，那我就自己定义
 * 关于创建二叉树我还是比较生疏的，关于哪几种算法，我都是没有掌握的特别扎实
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef char ElemType;
// 创建二叉树定义
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
// 创建二叉树
void CreateBiTree(BiTree *T)
{
    char ch = NULL;
    scanf("%c", &ch);
    // "" ' ' 这两个引号是有比较大的区别的，自己要注意
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        // 创建结点的时候出了问题
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
void func(char root){
    printf("%c ",root);
}
// 打印二叉树
void Print_BiTree(BiTree T){
    if(T != NULL ){
        func(T->data);
        Print_BiTree(T->lchild);
        Print_BiTree(T->rchild);
    }
}
// 打印
void Print(char a,char x){
    if(a >= x) printf("%c ",a);
}
// 遍历算法 采用递归
void Traverse_Tree(BiTree T,char x){
    if(T != NULL){
        Print(T->data,x);
        Traverse_Tree(T->lchild,x);
        Traverse_Tree(T->rchild,x);
    }
}
int main(){
    BiTree T = NULL;
    char c = NULL;
    CreateBiTree(&T);
    Print_BiTree(T);
    // 清空键盘的缓冲区
    while((c = getchar()) != EOF && c != '\n');
    printf("\n");
    printf("输入x值，进行遍历:");
    scanf("%c",&c);
    Traverse_Tree(T,c);
    return 0;

}