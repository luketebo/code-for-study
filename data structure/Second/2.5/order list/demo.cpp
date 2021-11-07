#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;
typedef int status;
typedef int elemtype;
typedef struct LNode
{
    elemtype data;
    struct LNode *next; //定义的*next为指向结构体LNode类型的指针
} LNode, *linklist;     // *linklist相等于一个列表头指针，也是结构体类型

//逆位序插入n个元素的值，建立带表头结点的单链表
status createlist(linklist &l, int n)
{
    int i;
    linklist p;
    /*
    l = (linklist)malloc(sizeof(linklist));
    */
    l = new LNode;
    l->next = NULL; //先建立一个带头结点的单链表
    for (i = n; i > 0; i--)
    {
        p = (linklist)malloc(sizeof(linklist)); //生成新结点
        cout << "请输入第" << i << "个数据：";
        cin >> p->data;
        p->next = l->next;
        l->next = p;
    }
    i = 0;
    cout << endl;
        cout<< "输出链表：";
    for (p = l->next; p != NULL; p = p->next)
        cout << p->data << "  ";
    cout << endl<< endl;
    return 0;
}

void mergelist(linklist &la, linklist &lb, linklist &lc)
{   //已知单链表la，lb以递增顺序排列
    //归并la，lb得到新链表lc，lc也以递增顺序排列

    linklist pa, pb, pc, p;
    pa = la->next;
    pb = lb->next;
    lc = pc = la;    //用la的头结点做lc的头结点
    while (pa && pb) //pa与pb都不为空时
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa; //pc指向lc中表中当前最后一个结点
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb; //插入剩余段
    free(lb);                //释放lb的头结点
    cout << endl;
    cout << "输出lc：";
    for (p = lc->next; p != NULL; p = p->next)
        cout << p->data << "  ";
    cout << endl <<endl;
}

int main()
{
    linklist la, lb, lc;
    cout << "创建la" << endl;
    createlist(la, 5);
    cout << "创建lb" << endl;
    createlist(lb, 4);
    mergelist(la, lb, lc);
}