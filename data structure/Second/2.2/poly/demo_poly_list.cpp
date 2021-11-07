#include <iostream>
using namespace std;
struct Node
{
    int coef;
    int expn;
    struct Node *next;
};
// 初始化链表
void Initlist(Node *&L)
{
    L = new Node;
    L->next = NULL;
    L->coef = 0;
    L->expn = 0;
}
//打印链表
void prin(Node *L)
{
    Node *p;
    p = L->next;
    while (p != NULL)
    {
        cout << p->coef << "X^" << p->expn << "+";
        p = p->next;
    }
    cout << endl;
}
//一元多项式相加

Node *AddPoly(Node *L1, Node *L2) //一元多项式相加
{
    Node *pa, *pb, *s, *pc, *p;
    Node *tc; //创建尾节点
    pc = new Node;
    pc->next = NULL; /*pc为新建单链表的头结点*/
    tc = pc;         /*tc始终指向新建单链表的最后结点*/
    pa = L1->next;
    pb = L2->next;                   //获得多项式单链表的第一个结点
    while (pa != NULL && pb != NULL) //pa,pb都不为空，就进行比较，否则，跳出while
    {
        if (pa->expn < pb->expn) //将*pa结点复制到*s并链到pc尾
        {
            s = new Node;
            s->coef = pa->coef;
            s->expn = pa->expn;
            s->next = NULL;
            tc->next = s;
            tc = s;
            pa = pa->next;
        }
        else if (pa->expn > pb->expn) //将*pb结点复制到*s并链到pc尾
        {
            s = new Node;
            s->coef = pb->coef;
            s->expn = pb->expn;
            s->next = NULL;
            tc->next = s;
            tc = s;
            pb = pb->next;
        }
        else //pa->expn=pa->expn时的情况
        {
            if (pa->coef + pb->coef != 0) //如果相加系数之和不为0，则将新结点插在tc后面
            {
                s = new Node;
                s->coef = pa->coef + pb->coef;
                s->expn = pa->expn;
                s->next = NULL;
                tc->next = s;
                tc = s;
            }
            pa = pa->next; //跳过当前的结点，继续后面的结点的比较
            pb = pb->next;
        }
    }
    //将尚未扫描完的余下结点复制并链接到pc单链表之后
    if (pa != NULL) //pb为空
        p = pa;
    else //pa为空
        p = pb;
    while (p != NULL)
    {
        s = new Node;
        s->coef = p->coef;
        s->expn = p->expn;
        s->next = NULL;
        tc->next = s;
        tc = s;
        p = p->next;
    }
    return pc;
}
void InsertNode(Node *&L, int c, int e, int i)
{
    Node *p, *q;
    int j = 1;
    q = new Node;
    q->coef = c;
    q->expn = e;
    q->next = NULL;
    p = L;
    while (j <= i)
    {
        p = p->next;
        ++j;
    }
    q->next = p->next;
    p->next = q;
}
int main()
{
    Node *La, *Lb, *Lc;
    Initlist(La);
    Initlist(Lb);
    Initlist(Lc);
    int la_length;
    cout << "请输入La链表的长度" << endl;
    cin >> la_length;
    int expn_a, coef_a;
    for (int i = 0; i < la_length; i++)
    {
        cout << "请输入第" << i + 1 << "个元素的系数与项数" << endl;
        cin >> coef_a >> expn_a;
        InsertNode(La, coef_a, expn_a, i);
        coef_a = 0;
        expn_a = 0;
    }
    int lb_length;
    cout << "请输入Lb链表的长度" << endl;
    cin >> lb_length;
    int expn_b = 0;
    int coef_b = 0;
    for (int i = 0; i < lb_length; i++)
    {
        cout << "请输入第" << i + 1 << "个元素的系数与项数" << endl;
        cin >> coef_b >> expn_b;
        InsertNode(Lb, coef_b, expn_b, i);
        coef_b = 0;
        expn_b = 0;
    }
    cout << "La链表：" << endl;
    prin(La);
    cout << "Lb链表：" << endl;
    prin(Lb);
    Lc = AddPoly(La, Lb);
    cout << "la与lb相加后的结果：" << endl;
    prin(Lc);
    return 0;
}
