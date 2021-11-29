/**
 * 作业：17 判断两棵树是否相等，那只要判断他们们的结点是否相同就可以，遍历的时候比较结点元素
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char ElemType;
typedef struct
{
    ElemType data;
    struct BiNode *lchild, *rchild; //现在暂时不用线索二叉树
} BiNode, *BiTree;
//创造一棵二叉树,传递一个指针
//神使用递归，人使用迭代
void CreateBiTree(BiTree *T)
{
    char ch = NULL;
    scanf("%c", &ch); //缓存区问题，这里面有一个回车
    //%c 为什么可以输入一大串字符？
    //这个键盘缓冲区我该怎么解决？

    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        //创造子树和遍历的方法有关系吗？
        //创造下一个结点，创造一个指针？
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        //创造左子树
        CreateBiTree(&(*T)->lchild); //这里应该是传递一个指向BiNode的指针
        //创造右子树
        CreateBiTree(&(*T)->rchild);
    }
}
void function(char t)
{
    printf("%c ", t);
}
//检索二叉树 我感觉单纯检索就不需要传递一个指针，只要把值传递了就可以
void PreOrder(BiTree T)
{
    if (T)
    {
        //这种方法的遍历好像还是太粗糙了，毕竟情况有很多种
        //遍历根结点
        function(T->data);
        //遍历左子树
        PreOrder(T->lchild);
        //遍历右子树
        PreOrder(T->rchild);
    }
}
void func(char a,char b){
    if(a != b) {
        printf("the BiTrees are not same\n");
        exit(1);
    }
}
void PreChange(BiTree T, BiTree L)
{
    if(T && L){
        func(T->data, L->data);
        PreChange(T->lchild, L->lchild);
        PreChange(T->rchild, L->rchild);
    }
    
}
int main()
{
    //可以使用一个讨巧的办法，我最后结果返回一个数组就可以了，比较数组中的元素，得出结果
    //定义一颗二叉树
    BiTree T = NULL;
    BiTree R = NULL;
    printf("now create the first bitree\n");
    CreateBiTree(&T);
    PreOrder(T);
    printf("\n");
    printf("now create the second bitree\n");
    //创建的时候出了问题，他给我生成了一个结点
    //他已经给我创建了一个根结点了，阿哲
    char cho;
    while ((cho = getchar()) != '\n' && cho != EOF);

    //终于把键盘缓冲区给干掉了，气死了，啊啊啊啊
    CreateBiTree(&R);
    PreOrder(R);
    printf("\n");
    PreChange(T,R);
    printf("the BiTrees are same\n");
    //   printf("********************************\n");
}