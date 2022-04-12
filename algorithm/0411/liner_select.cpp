#include<iostream>
#include<vector>
using namespace std;
void Linear_select(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int index=0;
    for(int i=0;i<n;i++){
        if(a[i]<a[index]){
            index=i;
        }
    }
    int temp=a[index];
    a[index]=a[k-1];
    a[k-1]=temp;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    Linear_select();
    return 0;
}