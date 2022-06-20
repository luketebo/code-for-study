/**
 * @file insertion.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * 插入排序
 */
#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;
typedef int element;
void Insert_sort(element arr[],int count){
    // 从 1 ~ count, 循环count - 1 次
    for(int i = 1; i < count; i++){
        /**
         * @brief 
         * 从数组中第二个元素开始，和前面比较，如果比前面小，就往前移
         * 升序
         */
        
        int temp = arr[i];
        // 从 i 个元素之前循环
        for(int j = i - 1; j >= 0; j--){
           if(temp < arr[j]){
               int b = 0;
                b = arr[j];
                arr[j] = temp;
                arr[j+1] = b;
           }   
        }
    }

}
int main(){
    element input[MAXSIZE];
    int count;
    cout<<"please input the arrays length"<<endl;
    cin>>count;
    while (count > MAXSIZE)
    {
        cout<<"the count is too large,please input new"<<endl;
        cin>>count;
    }
    cout<<"please input the arrays"<<endl;
    for(int i = 0; i < count; i++ ){
        cin>>input[i];
    }
    cout<<"--------排序前---------"<<endl;
    for(int i = 0; i < count; i++ ){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    Insert_sort(input,count);
    cout<<endl;
    cout<<"--------排序后---------"<<endl;
    for(int i = 0; i < count; i++ ){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}