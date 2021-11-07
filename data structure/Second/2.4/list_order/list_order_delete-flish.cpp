//有序表的删除（链表)
//可删除线性表中所有值为item的数据元素 时间复杂度O(n),空间复杂度O(1);
//就是输入一个数组，在顺序表中查找并删除
#include<iostream>
#include<cstdlib>
using namespace std;
//创建一个结构体
typedef struct Node
{
    int data;//数据域
    int* next;//指针域
};
//初始化链表
void Initlist(Node &L){
    L.next=new int[100];
    if(!L.next) exit(0);
    L.data=0;
}
//链表赋值
void Createlist(Node &L,int n){
    for(int i=0;i<n;i++){
        cin>>L.next[i];
        L.data++;
    }
}
//删除链表中的某个值
void Deletelist(Node &L,int i){
    if((i<1)||(i>L.data)) exit(0);
    int j=0;
    for(j=i;j<=L.data-1;j++){
        L.next[j-1]=L.next[j];
        --L.data;
    }
}
int prin(Node &L)
{
    int i;
    for(i=0;i<L.data;i++)
        cout<<L.next[i]<<' ';
    cout<<endl;
}
int main(){
    Node L;
    Initlist(L);  //初始化链表
    cout<<"请输入链表的长度"<<endl;
    int length,elem;
    cin>>length;
    cout<<"请输入链表的元素"<<endl;
    Createlist(L,length);
    cout<<"打印链表"<<endl;
    prin(L);
    cout<<"请输入你要删除哪个位置的元素"<<endl;
    int del;
    cin>>del;
    Deletelist(L,del);
    cout<<"打印链表"<<endl;
    prin(L);
    return 0;
}
