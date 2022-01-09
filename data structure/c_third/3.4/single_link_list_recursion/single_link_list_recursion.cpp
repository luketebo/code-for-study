//作业11：单链表的递归操作   p86 10
/********************
 * 已知f为点链表的表头指针，链表中存储的都是整形数据
 * 1.求链表中的最大整数
 * 2.求链表中结点个数
 * 3.求所有整数的平均值
 */
#include<iostream>
using namespace std;
//单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*linklist;
//初始化
void Initlink(linklist &s){
    s = new LNode;
    s->next = NULL;
    return;
}
void Createlink(linklist &s,int n){
    linklist r,p;
    int i = 0;
    s = new LNode;
    s->next = NULL;
    r = s;
    while(1){
        p = new LNode;
        cin>>p->data;
        p->next = NULL;
        r->next = p;
        r = p;
        i++;
        if(i==n) break;
    }
    return;
}
//求链表的最大整数
int max_link(linklist s){
    int max;
    if(s->next==NULL) return s->data;
    else {
        max = max_link(s->next);
        return s->data >= max?s->data:max;
    }
}
//求链表的结点个数
int node_link(linklist s){
    linklist  p;
    p = s->next;
    int i=0;
    while(p){
        i++;
        cout<<p->data<<endl;
        p = p->next;
    }
    return i;

}
//求链表结点数，递归做法
double sum_node(linklist s,double sum){
    if(s->next != NULL){
        sum = sum + 1;
        return sum_node(s->next,sum);
    }else{
        return sum + 1;
    }
}
//求所有整数的平均值
double aver_link(linklist l,double sum,int i){
    if(l->next != NULL) {
        sum = sum + l->data;
        return aver_link(l->next,sum,i+1);
    }else {
       double ave = 0;
       ave = (sum + l->data)/(i+1);
       return ave;
    }

}
int main(void){
    linklist s;
    int n;
    int i=0;
    double sum = 0;
    Initlink(s);
    while(1){
        cin>>n;
        if(n==0) break;
        Createlink(s,n);
        cout<<"aver:"<<aver_link(s->next,sum,i)<<endl;
        cout<<"node:"<<sum_node(s->next,sum)<<endl;
        cout<<"max:"<<max_link(s->next)<<endl;
    }
    


    
    return 0;
}