//作业5：顺序表的删除
#include <stdio.h>
#include <stdlib.h>
struct link
{
    int num;
    struct link *next;
};
int main()
{
    int n,i;
    struct link *head,*p;
    printf("How many numbers do you want to input:");
    scanf("%d",&n);
    head=(struct link*)malloc(sizeof(struct link));//创建头结点
    p=(struct link*)malloc(sizeof(struct link));//申请第一个结点
    head->next=p;//链接头结点和首结点
    printf("Please input numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p->num);
        p->next=(struct link*)malloc(sizeof(struct link));//申请下一个节点
        p=p->next;//将该节点和下一个节点连起来
    }
    p=head->next;//由于第一个循环已经将链表移到末尾，所以这里要将链表移到首结点开始打印
    for(i=0;i<n;i++)
    {
        printf("%d ",p->num);
        p=p->next;
    }
    printf("\n");
    printf("Please input the delete number:\n");
    int a=0;
    scanf("%d",&a);
    printf("Now will delete the number\n");
    int j=0;
    printf("%d",&a);
    for(j=a;j<p->num-1;j++){
        p->next[j-1]=p->next[j];
        --p->num;
    }
    p=head->next;//由于第一个循环已经将链表移到末尾，所以这里要将链表移到首结点开始打印
    for(i=0;i<n;i++)
    {
        printf("%d ",p->num);
        p=p->next;
    }
    return 0;
}