//一元多项式的运算
#include <iostream>
using namespace std;
typedef struct
{
    float coef; //系数
    int expn;   //指数
} polynomial;
typedef struct
{
    polynomial *elem;
    int length;
} sqlist;
void Initlist(sqlist &L)
{
    L.elem = new polynomial[100];
    if (!L.elem)
        exit(overflow);
    L.length = 0;
    
}
void Createlist(sqlist &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第" << i + 1 << "个元素的系数" << endl;
        cin >> L.elem[i]; //输入的值，怎么给结构体输入数据？
    }
    cout << "打印一元多项式" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << L.elem[i] << " ";
    }
}
void add(sqlist &L,sqlist &N)
{
}
void subtraction(sqlist &L,sqlist &N){

}
void multiplication(sqlist &L,sqlist &N){

}
int main(){
    sqlist L;
    sqlist B;
    Initlist(L);
    Initlist(B);
    Createlist(L,5);
    Createlist(B,4);
}
