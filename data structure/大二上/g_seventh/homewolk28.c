/********
 * 循环队列的操作 p85 2(8)  第三章
 * 如果允许在循环队列的两端都可以进行插入与删除
 * 1.写出循环队列的类型定义
 * 2.写出从队尾删除和从队头插入的算法
 * 
 * 对于队列来说，还需要判断是否为空，是否满队
 * 判断为空 头指针等于尾指针 front == rear;
 * 判断为满 front == (rear + 1) % MAXSIZE
 * 问题 ：
 * 这个循环链表的结构 
 * 还有这个循环链表他们 front rear MAXSIZE 他们之间的关系， 因为这些原因，有些函数就不需要写，比如说判断队列是否为空
 * 判断队是否满队
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"
typedef int QELemType;
// 定义循环队列
#define MAXSIZE 100
typedef struct
{
    QELemType *base; // 存储空间的基地址
    int front;       // 头指针
    int rear;        // 尾指针
} SqQueue;
int Empty(SqQueue *t)
{
    if (t->front == t->rear)
    {
        return 1;
    }
    else
        return 0;
}
int Full(SqQueue *t)
{
    if (t->front == (t->rear + 1) % MAXSIZE)
        return 1;
    else
        return 0;
}
// 初始化循环队列
void InitSqQueue(SqQueue *t)
{
    // 为base
    t->base = (SqQueue *)malloc(MAXSIZE * sizeof(SqQueue)); // 为base 分配内存空间 100
    if (t->base != NULL)
    {
        t->front = t->rear = 0;
    }
    return;
}
// 创建队列
void Insert_Front()
{
}
// 队尾删除
void Del_Rear(SqQueue *t)
{
    if(t->front == t->rear){
        printf("the queue is empty\n");
        return;
    }
    t->front = (t->front + 1) % MAXSIZE;
}
// 队头插入 前插法？ 入队？
void CreateSqQueue(SqQueue *t)
{
    printf("please input the element\n");
    int element = 0;
    while(Full(t) != 1){
        scanf("%d", &element);
        
        // 清空键盘缓冲区
        char ch;
        while((ch = getchar()) != EOF && ch != '\n');
        if(element == -1) break;
        // 进队元素赋给后指针所指的位置
        t->base[t->rear] = element;
        t->rear = (t->rear + 1) % MAXSIZE;
    }
    return ;
}
// 寻找队列的长度
int Length_SqQueue(SqQueue *t){
    return (t->rear - t->front + MAXSIZE) % MAXSIZE;
}
// 打印队列元素
void Print_SqQueue(SqQueue *t){
    int i;
    int length = Length_SqQueue(t);
    printf("循环队列元素：\n");
    // length = 5;  打印元素的递归有点操作
    for(int i = 0; i < length; i++){
        printf("%d ",t->base[(t->front + i) % MAXSIZE]);
    }
}
int main()
{
    SqQueue t;
    InitSqQueue(&t);
    CreateSqQueue(&t);
    Print_SqQueue(&t);
    printf("\n");
    Del_Rear(&t);
    Print_SqQueue(&t);
    return 0;
}
