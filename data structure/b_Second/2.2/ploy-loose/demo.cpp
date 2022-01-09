//疏松多项式的运算
#include <iostream>
using namespace std;
typedef struct Node
{
    int coef; //系数
    int expn; //指数
    struct Node *next;
} Node, *Polynomial;
void Createlist(Polynomial &p, int n)
{
    Polynomial s, pre, q;
    p = new Node;
    p->next = NULL;
    for (int i = 1; i <= n; i++)
    {
        s = new Node;
        cout<<"请输入第"<<i<<"个元素的系数与指数"<<endl;
        cin >> s->coef >> s->expn;
        pre = p;
        q = p->next;
        while (q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}
void addpolynomial(Polynomial &pa, Polynomial &pb)
{
    Polynomial p1, p2, p3, r;
    p1 = pa->next;
    p2 = pb->next;
    p3 = pa;
    while (p1 && p2)
    {
        if (p1->expn == p2->expn)
        {
            int sum = p1->coef + p2->coef;
            if (sum != 0)
            {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                r = p2;
                p2 = p2->next;
                delete r;
            }
            else
            {
                r = p1;
                p1 = p1->next;
                delete r;
                r = p2;
                p2 = p2->next;
                delete r;
            }
        }
        else if (p1->expn < p2->expn)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
        p3->next = p1 ? p1 : p2;
        delete pb;
    }
}
//打印链表
void prin(Polynomial L)
{
    Polynomial p;
    p = L->next;
    while (p != NULL)
    {
        cout << p->coef << "X^" << p->expn << "+";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    Polynomial La, Lb;
    int la_length, lb_length;
    la_length = 0;
    lb_length = 0;
    cout << "请输入第一个多项式的元素个数：" << endl;
    cin >> la_length;
    Createlist(La, la_length);
    prin(La);
    cout << "请输入第二个多项式中元素的个数：" << endl;
    cin >> lb_length;
    Createlist(Lb, lb_length);
    prin(Lb);
    cout << "现进行多项式相加" << endl;
    addpolynomial(La, Lb);
    cout << "结果:"<<endl;
    prin(La);
    return 0;
}