//一元多项式的运算
#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int b[10];
    cout << "请输入第一个一元多项式每一项的值，从0元开始：" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cout << "请输入第二个一元多项式的值，从0元开始:" << endl;
    for (int j = 0; j < 10; j++)
    {
        cin >> b[j];
    }
    int c[10];
    cout << "两个一元多项式相加的值为：" << endl;
    for (int i = 0; i < 10; i++)
    {
        c[i] = a[i] + b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }
    cout << "两个一元多项式相减的值为：" << endl;
    for (int i = 0; i < 10; i++)
    {
        c[i] = a[i] - b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }
    cout << "两个一元多项式相乘的值为：" << endl;
    for (int i = 0; i < 10; i++)
    {
        c[i] = a[i] * b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}