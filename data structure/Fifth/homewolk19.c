/*****
 * 作业：19 计算二叉树的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值)
 * 宽度本来是指什么？那就用层次遍历
 */
#define INITQUEUE 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct{
    ElemType data;
    struct BiNode * lchild, *rchild;
}BiNode,*BiTree;
//  创建队列
typedef struct{
    BiNode * front, *tail;
    int size;
}Queue;
//  初始化队列
int InitQueue(Queue Q){
    Q.front = (BiNode *)malloc(INITQUEUE * sizeof(BiNode));
    if(!Q.front){
        return 0;
    }
    Q.tail = Q.front;
    Q.size = INITQUEUE;
}
//  判断队列是否为空
int EmptyQueue(Queue Q){
    if(Q.tail == Q.front){
        return 1;
    }else{
        return 0;
    }
}
//  进队
int EnQueue(Queue Q,BiNode e){
    if((Q.tail - Q.front + INITQUEUE)% INITQUEUE == INITQUEUE - 1);
    {
        return 0;
    }
    *Q.tail = e;
    Q.tail++;
    return 1;
}
//  出队
int DeQueue(Queue Q,BiNode e){
    if(Q.front == Q.tail){
        return 0;
    }
    e = *Q.front;
    Q.front++;
    return 1;
}
// 创建一颗二叉树
void CreateBiTree(BiTree *T){
    char ch = NULL;
    scanf("%c",&ch);
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
// 层次遍历  用栈来存储
void LevOrder(BiTree T){
    if(T == NULL){
        return 0;
    }
    BiNode e;
    Queue Q;
    int levelcount = 0;
    int curlevel = 1;
    int nextlevel = 0;
    InitQueue(Q);
    EnQueue(Q,*T);
    while(!EmptyQueue(Q)){
        DeQueue(Q,e);
        printf("%c ",e.data);
        curlevel--;
        if(NULL != e.lchild){
            EnQueue(Q,e.lchild);
            nextlevel++;
        }
        if(NULL != e.rchild){
            EnQueue(Q,e.rchild);
            nextlevel++;
        }
        if(0 == curlevel){
            levelcount++;
            printf("第%d层结点遍历结束！\n",levelcount);
            curlevel = nextlevel;
            nextlevel = 0;
        } 
    }
    return 1;
}
int main(){

}