#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct
{
    int *elem;
    int length;
}SqList;
int InitList(SqList &L)
{
    L.elem=new int[100];
    if(!L.elem) return 0;
    L.length=0;
    return 1;
}
void CreateList(SqList &L,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
        L.length++;
    }
}
int InsertList(SqList &L,int i,int e)
{
    if((i<1)||(i>L.length+1)) return 0;
    if(L.length==100) return 0;
    L.length++;
    for(int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    return 1;
}
int DeleteList(SqList &L,int i)
{
    if((i<1)||(i>L.length)) return 0;
    for(int j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];
    --L.length;
    return 1;
}
int prin(SqList &L)
{
    int i;
    for(i=0;i<L.length;i++)
        cout<<L.elem[i]<<' ';
    cout<<endl;
    return 0;
}
int main()
{
    SqList Pa;
    cout<<"初始化链表"<<endl;
    InitList(Pa);
    cout<<"创建链表且元素不超过五个"<<endl;
    CreateList(Pa,5);
    cout<<"刚创建的链表"<<endl;
    prin(Pa);
    /*
    cout<<"插入4.8两个元素"<<endl;
    InsertList(Pa,4,8);
    cout<<"打印链表"<<endl;
    prin(Pa);
    */
    cout<<"删除链表中的4号元素"<<endl;
    DeleteList(Pa,4);
    cout<<"打印链表"<<endl;
    prin(Pa);
    return 0;
}