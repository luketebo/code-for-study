/*****
 * 作业：19 计算二叉树的宽度（二叉树的最大宽度是指二叉树所有结点中个数的最大值)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct{
    ElemType data;
    struct BiNode * lchild, *rchild;
}BiNode,*BiTree;
//创建一颗二叉树
void CreateBiTree(BiTree *T){
    char ch = NULL;
    scanf("%c",&ch);
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}