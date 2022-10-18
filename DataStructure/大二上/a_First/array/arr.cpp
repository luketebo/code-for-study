//作业2：
//在一维数组a中顺序查找某个值等于e的元素，并返回其所在的下标
#include<iostream>
using namespace std;
int main()
{
    int a[5];
    cout<<"请输入a数组中的值:"<<endl;
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    int target;
    cout<<"请输入target值:"<<endl;
    cin>>target;
    int b=0;
    for(int i=0;i<5;i++){
        if(a[i]==target) {
            cout<<i;
            b++;
            }
    }
    if(b==0) cout<<"erro"<<endl;
    return 0;
}