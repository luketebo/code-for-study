//疏松多项式的运算
#include <iostream>
using namespace std;
//创建链表
typedef struct pnode
{
    float coef;//系数
    int expn;//指数
    struct pnode *next;   //指针域
} pnode, *polynomial;
//多项式的创建
void cretepolyn(polynomial &p, int n)
{
    p = new pnode;
    p.next = null;
    for (int i = 1; i <= n; i++)
    {
        s = new pnode;
        cin >> s.coef >> s.expn;
        pre = p;
        q = p.next;
        while (q && q.expn < s.expn)
        {
            pre = q;
            q = q.next;
        }
        s.next = q;
        pre.next = s;
    }
}
//多项式加法的实现
void addpolyn(polynomial &pa, polynomial &pb)
{
    p1 = pa.next;
    p2 = pb.next;
    p3 = pa;
    while (p1 && p2)
    {
        if (p1.expn == p2.expn)
        {
            sum = p1.coef + p2.coef;
            if (sum != 0)
            {
                p1.coef = sum;
                p3.next = p1;
                p3 = p1;
                p1 = p1.next;
                r = p2;
                p2 = p2.next;
                delete r;
            }
            else
            {
                r = p1;
                p1 = p1.next;
                delete r;
                r = p2;
                p2 = p2.next;
                delete r;
            }
        }
        else if (p1.expn < p2.expen)
        {
            p3.next = p1;
            p3 = p1;
            p1 = p1.next;
        }
        else
        {
            p3.next = p2;
            p3 = p2;
            p2 = p2.next;
        }
    }
    p3.next = p1 ? p1 : p2;
    delete pb;
}
//疏松多项式的减法
//疏松多项式的乘法
int main()
{
    pnode h;
    h=new int pnode[];
    


}