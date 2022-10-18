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
// 初始化链表 初始化有问题，但是我大概知道
void InitList(LNode *t)
{
    t = (LNode *)malloc(sizeof(LNode));
    //t->next = NULL;
}
// 对链表进行赋值
void CreateList(LNode *t)
{
    LNode *p; // 创建两个指针 一个指前面
    LNode *r; // 一个值后面
    r = t;
    int i = 0;
    int j;
    while (i != -1)
    {
        scanf("%d", &j);
        if (j != 0)
        {
            p = (LNode *)malloc(sizeof(LNode)); // 一个结点
            p->data = j;
            r->next = p;
            r = p;
        }
        else
        {
            i = -1;
            r->next = NULL;
        }
    }
}
// 打印链表
void Print_List(LNode *t)
{
    printf("the printf:\n");
    LNode *q = t->next;
    if (q == NULL)
    {
        printf("the list is null\n");
        return;
    }
    // 重要部分
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
}
// 对单链表进行分离  分隔标准 以 0 为界  单链表分隔的时候麻烦的很
void Divide_List(LNode *a, LNode *l, LNode *r)
{
    // 因为有头结点的存在，所以我要把这三个头结点通通跳过

    LNode *t = a->next;
    LNode *ti = a;
    LNode *li = l;
    LNode *ri = r;
    if (t == NULL)
    {
        printf("the list is null\n");
        return;
    }
    // 原题没有给出等于0的情况，我们这里就不作讨论
    while (t != NULL)
    {
        if (t->data > 0)
        {

            //li = (LNode *)malloc(sizeof(LNode));   // 创建新的结点？ 无必要
            li->next = t; // 将t连接到li单链表末尾
            li = t;
            t = t->next; //  t 指针后移
                         // 最后面结点并没有断开，懂我意思吗?
        }
        else if (t->data < 0)
        {
            ri->next = t;
            ri = t;
            t = t->next;
        }
        // 现在最后结点已经被我断开了， 这算是一个关键点
        li->next = NULL;
        ri->next = NULL;
    }
    return;
}
int main()
{
    LNode *t, *r, *l;
    // 初始化
    /*
    InitList(t);
    InitList(l);
    InitList(r);
    */
    t = (LNode *)malloc(sizeof(LNode));
    r = (LNode *)malloc(sizeof(LNode));
    l = (LNode *)malloc(sizeof(LNode));
    CreateList(t);
    Print_List(t);
    printf("\n");
    Divide_List(t, l, r);
    Print_List(r);
    printf("\n");
    Print_List(l);
    return;
}
