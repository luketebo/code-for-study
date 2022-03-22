#include<iostream>
using namespace std;
// 合并
void merge(int arr[], int low,int mid,int high){
    int tempA[100],tempB[100];
    
}
// 分割
void MergeSort(int arr[],int low,int high){
    if(low >= high)
    return ;
    int mid = low + (high - low) / 2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid,high);
    merge(arr,low,mid,high);
}
int main(){



    return 0;
}