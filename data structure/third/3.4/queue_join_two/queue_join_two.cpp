//作业10：两端都可以入队、出队的循环队列 p85 8
//1.写出循环队列的类型定义
//2.写出“从队尾删除”和“从队头插入”的算法
#include <iostream>
using namespace std;
#define maxsize 10
//创建循环队列
typedef struct
{
    int *va;
    int front;
    int rear;
} Sqqueue;
//初始化
void Initqueue(Sqqueue &s)
{
    s.va = new int[10];
    if (!s.va)
        exit(0);
    s.front = s.rear = 0; //
}
//判断队空
int empty(Sqqueue s)
{
    if (s.front = s.rear)
        return 1;
    else
        return 0;
}
//队尾删除
int que_del(Sqqueue &s, int &x)
{
    if (s.front == s.rear)
    {
        return 0;
    }
    else
    {
        x = s.va[s.rear];
        s.rear = (s.rear - 1 + maxsize) % maxsize;
        return 1;
    }
}
//队头插入
int que_insert(Sqqueue &s, int x)
{
    if (s.rear == (s.front - 1 + maxsize) % maxsize)
        return 0;
    else
    {
        s.front = (s.front - 1 + maxsize) % maxsize;

        s.va[s.front] = x;

        return 1;
    }
}
void show(Sqqueue &s)
{

    while (s.front != s.rear)
    {
        cout << s.va[s.front] << " ";
        s.front = (s.front + 1) % maxsize;
    }
}
int main(void)
{
    Sqqueue gcc;
    Initqueue(gcc);
    // que_beg_insert(gcc);
    // que_en_del(gcc);
    int a[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        que_insert(gcc, a[i]);
    }
    //  show(gcc);
    int b[2] = {0};
    
    for (int i = 0; i < 2; i++)
    {
        que_del(gcc, b[i]);
    }
    show(gcc);
    
}