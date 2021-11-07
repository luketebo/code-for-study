//用链表实现两个集合的差运算
#include<iostream>
using namespace std;
typedef struct Node{
    int *elem;
    int length;
}Node;
//初始化链表
void Initlist(Node *L){
    L->elem =new int[100];
    if(!L->elem) exit(0);
    L->length=0;
}
//创建链表
void Createlist(Node *L,int n){
    for(int i=0;i<n;i++){
        cout<<"请输入第"<<i+1<<"个元素"<<endl;
        cin>>L->elem[i];
        L->length++;
    }
}
void prin(Node *L){
    int i=0;
    for(i=0;i<L->length;i++)
    {
        cout<<L->elem[i]<<" ";
    }
    cout<<endl;
    cout<<"长度为："<<L->length<<endl;
}
void Diff(Node *La,Node *Lb,Node *Lc){
    int i=0;
    int j=0;
    for(i=0;i<La->length;i++){
        int k=0;
        for(j=0;j<Lb->length;j++){
            if(Lb->elem[j]==La->elem[i])
            k++;
        }
        if(k==0)
            Lc->elem[Lc->length++]=La->elem[i];
    }
}
int main()
{
    Node *La,*Lb,*Lc;
    int La_length=0;
    int Lb_length=0;
    /*
    Initlist(La);
    Initlist(Lb);
    */
    cout<<"请输入第一个集合的个数"<<endl;
    cin>>La_length;
    Createlist(La,La_length);
    prin(La);
    cout<<"请输入第二个集合的个数"<<endl;
    cin>>Lb_length;
    Createlist(Lb,Lb_length);
    prin(Lb);
    cout<<"进行差运算"<<endl;
    Diff(La,Lb,Lc);
    prin(Lc);

}