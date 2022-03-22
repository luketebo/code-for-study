#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define MAX 10
void Producer(int num){
    if(num > 10){
        num++;
        cout<<"Producer: product:"<<num<<endl;
        
    }
}
void Consumer(int num){

}
int main(){
    int num = 0;
    HANDLE h;
    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Producer,NULL,1,0);
    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Consumer,NULL,1,0);

    

}