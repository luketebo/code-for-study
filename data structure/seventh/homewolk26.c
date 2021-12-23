/**
 * 单链表的分解 p53 2(5)  第二章
 * 设计算法将一个带头结点的单链表A分解为两个具有相同数据结构的链表b和c，其中b表的结点为
 * a表中值小于0的结点，而c表的结点为a表中值大于0的结点，链表a中的元素为非0整数，要求
 * b和c表利用a表的结点
 * 
 * 我学了当没学，学了个寂寞
 *  你还记得到单链表的数据结构形式吗？
 *  单链表是不是有头结点呀？ 首元结点？
 *  有头结点，就是在第一个元素之前，有一个那个叫头结点
 *  敲回车的时候不要发出声音
 *  怎么创建单链表？
 * 1. 初始化链表，产生一个头结点 到底要创建多少个头结点，书上我还是感觉有问题   
 * 2. 创建链表，前插和后插法
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef int ElemType;
typedef struct
{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;
void InitList(LinkList t)
{
    // 生成新结点作为头结点，用头指针指向头结点
    t = (LNode *)malloc(sizeof(LNode));
    t->next = NULL;
    return;
}
// 采用后插法，保证我输入元素的顺序没错
/**
 * 后插法，我是照着书上写得，走不动也很正常
 */
// 我自己来写一个后插创建单链表
void CreateLNode(LinkList *t) // 指向LNode 的指针
{
    t = (LNode *)malloc(sizeof(LNode));
    (*t)->next = NULL;
    LinkList r;
    r = t;
    
}
/*
void CreateLNode(LinkList *t)
{
    // 这里的头结点，我有疑惑，为什么要这么创建
    t = (LNode *)malloc(sizeof(LNode)); // 创建一个带头结点的空链表
    (*t)->next = NULL;
    LinkList r;
    r = t;
    int n = 0;
    printf("please input the element numbers\n");
    scanf("%d", &n);
    // 清空键盘缓冲区
    char ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        ;
    for (int i = 0; i < n; i++)
    {
        LinkList p = (LNode *)malloc(sizeof(LNode));
        printf("please input the element\n");
        scanf("%d", &p->data);
        // 清空键盘缓冲区
        while ((ch = getchar()) != EOF && ch != '\n')
            ;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
*/
// b and c 利用a表中的结点
/**
 * 那只要创建两个链表，然后对a表中的元素进行分类，如果怎么怎么的，就加入另一个b 或者 c 链表中，反正也只是
 * 改变指针就可以咯
 */
void DivideLNode()
{
}
void Print_List(LinkList *p)
{
    while (p)
    {
        printf("%d ", (*p)->data);
        p = (*p)->next;
    }
    printf("\n");
}
int main()
{
    LinkList a;
    CreateLNode(&a);
    Print_List(&a);
}