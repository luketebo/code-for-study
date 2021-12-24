/**
 * 单链表的最大元素 p53 2(6)  第二章
 *  设计一个算法，通过一趟遍历能够确定长度为n的单链表中值最大的结点
 *  确实需要创建头结点，但是可以不用通过初始化
 *  基本完成但是有一点点小问题
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef int ElemType;
// 定义一个单链表结构体
typedef struct
{
    ElemType data;
    struct LNode *next;
} LNode, *LNodeList; // 疑惑
// 创建单链表 采用后续插入法
void CreateLNode(LNode *t)
{
    LNode *p; // 新建一个结点指针
    LNode *r; // 在建立一个尾指针
    int i = 1;
    int j;
    r = t;
    while (i != 0)
    {
        scanf("%d", &j);
        if (j != -1)
        {
            p = (LNode *)malloc(sizeof(LNode)); // 建立一个新结点
            p->data = j;
            r->next = p; // 尾指针的指针域指向新结点p
            r = p;       // 再让尾指针放在p后面，尾指针永远在最后
        }
        else
        {
            i = 0;
            r->next = NULL;
        }
    }
}
// 打印单链表  少了一个元素 啥原因呢？ 
void Print_List(LNode *l)
{
    LNode *p = l->next;
    printf("该链表的内容为：");
    while (p != NULL)  // p->next 改成了 p->data 就可以了,并没有。还是有问题，目前还没解决，打印有点点问题
    {
        printf("%d ", p->data);  // 怎么指向头结点之后的首元结点
        p = p->next;
    }
    printf("\n");
}
// 算法遍历实现
void Traverse_List(LNode *t)
{
    int maxdata = 0;
    // 一个值得注意的点，我们要跳过头结点，这样更方便我们去操作
    LNode *p = t->next;
    while(p->next != NULL)  
    {
        if(maxdata < p->data)
        {
            maxdata = p->data;
        }
        p = p->next;
    }
    printf("the maxdata is %d\n",maxdata);
}
int main()
{
    LNode *l;
    l = (LNode *)malloc(sizeof(LNode));
   // m = (LNode *)malloc(sizeof(LNode));
    printf("用尾插法插入链表 l\n");
    CreateLNode(l);
    Print_List(l);
    printf("现在进行算法遍历\n");
    Traverse_List(l);
}