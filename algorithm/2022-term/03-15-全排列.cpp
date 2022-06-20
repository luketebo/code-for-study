/**
 * @file arrange_full.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * 全排列
 * 从n个不同元素中任取m（m≤n）个元素，按照一定的顺序排列起来，叫做从n个不同元素中取出m个元素的一个排列。
 * 当m=n时所有的排列情况叫全排列。
 * 公式：全排列数f(n)=n!(定义0!=1)
 * */
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
// 暴力枚举
void enumeration(char a[],int length){
    
}
// 递归算法
void Arrange_Full(char a[],int begin,int end){
     int i,j;
    if(begin == end)  
    {
        for(i=0; i<=end; i++) 
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(j=begin; j<=end; j++)
        {
            swap(a[j],a[begin]);  
            Arrange_Full(a,begin+1,end); //递归调用
            swap(a[j],a[begin]); 
        } 
    }
}
int main(){
    char a[MAXSIZE] = {0};
    cout<<"please input the array:"<<endl;
    cin>>a;
    int length = strlen(a);
    cout<<"-----------排列后----------"<<endl;
    Arrange_Full(a,0,length - 1);    
   return 0; 
}