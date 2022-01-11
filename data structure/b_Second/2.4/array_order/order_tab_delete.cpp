//作业5：顺序表的删除操作,也是用链表来做的吗？
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a[10];
    cout<<"请输入a数组中的值:"<<endl;
    for(int i =0;i<10;i++){
        cin>>a[i];
    }
    cout<<"a数组中的值："<<endl;
    for(int i =0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"请输入你要删除的值:"<<endl;
    cin>>target;
    vector<int> p;
    for(int i=0;i<10;i++){
        if(a[i]!=target) p.push_back(a[i]);
    }
    cout<<"删除target值之后的数组："<<endl;
    if(p.size()==0) cout<<"null"<<endl;
    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}