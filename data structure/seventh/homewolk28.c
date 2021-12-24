/********
 * 循环队列的操作 p85 2(8)  第三章
 * 如果允许在循环队列的两端都可以进行插入与删除
 * 1.写出循环队列的类型定义
 * 2.写出从队尾删除和从队头插入的算法
 * 
 * 对于队列来说，还需要判断是否为空，是否满队
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef int QELemType;
// 定义循环队列
#define MAXSIZE 100;
typedef struct
{
    QELemType *base; // 存储空间的基地址
    int front;       // 头指针
    int rear;        // 尾指针
} SqQueue;
// 初始化循环队列
void InitSqQueue(SqQueue *t)
{
    // 为base
    t = (SqQueue *)malloc(sizeof(SqQueue*MAXSIZE)); // 为base 分配内存空间 100 
    if (t->base != NULL)
    {
        t->front = t->rear = 0;
    }
    return;
}
// 创建队列
void CreateSqQueue()
{

}
// 队尾删除
void Del_Rear()
{
}
// 队头插入 前插法？ 入队？
void Insert_Front()
{

}
int main()
{
}
