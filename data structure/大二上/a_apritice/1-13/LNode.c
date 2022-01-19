/**
 * @file demo.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 单链表的删除
 * 
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef int ElemType;
// 单链表
typedef struct
{
    ElemType data;      // 数据域
    struct LNode *next; // 指向下一个结点
    //  struct LNode *first; // 双链表
} LNode, *LinkList;
// 顺序表
typedef struct
{
    ElemType *data; // 这个结点就是存储数据的
    int length;
} Node;
// 顺序表初始化
void InitNode(Node *t)
{
    t->data = (Node *)malloc(sizeof(Node) * 100);
    if (t->data == NULL)
        exit(0);
    t->length = 0;
}
// 单链表初始化需要头结点 或者创建实例化的时候直接弄一个头结点
void InitLNode(LinkList *t)
{
    // 初始化一个头结点
    t = (LNode *)malloc(sizeof(LNode));
    (*t)->next = NULL;
}
// 创造一个单链表
void CreateLNode(LinkList *t)
{
    int n = 0;
    LinkList p; // 有没有*号呢？
    printf("单链表的长度:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", p->data);
        p->next = (*t)->next;
        (*t)->next = p;
    }
}