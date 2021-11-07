//试编写双栈初始化，判断栈空，栈满，进栈和出栈等算法的函数
#define max 10;
#include <iostream>
using namespace std;
typedef struct
{
    int top[2], bot[2];
    int *v; //栈数组
    int m;  //最大可容纳元素的个数；
} Dblstack;
//初始化双栈
void InitStack(Dblstack &s)
{
    cout<<"now this is Initing"<<endl;
    s.m = 10;
    s.v = new int[10];
    if(!s.v) exit(0);
    s.top[0] = s.v[0];
    s.bot[0] = s.v[0];
    s.top[1] = s.v[9];
    s.bot[1] = s.v[9];
}
//判断栈空
void Empty(Dblstack &s){
    if(s.top[1]-s.top[0]==9) {
        cout<<"the stack is empty"<<endl;
    }
    else cout<<"the stack is not empty"<<endl;
}
//判断栈满
void Fill(Dblstack &s){
    if(s.top[1]-s.top[0]==1){
        cout<<"the stack is filled"<<endl; 
    }else cout<<"the stack is not filled"<<endl; 
}
//进栈
void go_stack(Dblstack &s){
    //分界点，两个栈进哪一个？
    int choice=0;
    cout<<"please input the choice which the stack you want go (0/1)?"<<endl;
    cin>>choice;
    int a[10];
    int n=0;
    cout<<"Please enter the number of array"<<endl;
    cin>>n;
    cin.ignore();
    while(n){
        if(n>10) {
            cout<<"the number of array is too long"<<endl;
            cout<<"please enter the number again"<<endl; 
            cin>>n;
        }
    }
    cout<<"please input the array which you want ?"<<endl;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    switch(choice) {
        case 0:
                //top[o],bot[0];
                for(int i = 0;i<n;i++){
                    if(s.top[0]==s.bot[1]) {
                        cout<<"the stack is filled"<<endl;
                        exit(0);
                    }
                    //这样只是值变了吧，具体的指针好像是没有任何改变的 
                    s.v[s.top[0]++]=a[i];
                } 
                break;
        case 1:
                //top[1],bot[1];
                for(int i=0;i<n;i++){
                    if(s.top[1]==s.bot[0]){
                        cout<<"the stack is filled"<<endl;
                        exit(0); 
                    }
                    s.v[s.top[1]--]=a[i];
                }
                break;
    }
}
//出栈
void leave_stack(Dblstack &s){
    int choice;
    cout<<"which stack element you want to leave(0&1)?"<<endl;
    cin>>choice;
    int la=0;
    int lb=0;
    switch(choice) {
        case 0:
                //top[o],bot[0];
                
                cout<<"how many elements you want to leave?"<<endl;
                cin>>la;
                for(int i = 0;i<la;i++){  
                    if(s.top[0]==s.bot[1]) {
                        cout<<"the stack is filled"<<endl;
                        exit(0);
                    }
                    //怎么边删边减
                    s.v[s.top[0]--]=0;
                } 
                break;
        case 1:
                //top[1],bot[1];
                
                cout<<"how many elements you want to leave?"<<endl;
                cin>>lb;
                for(int i=0;i<lb;i++){
                    if(s.top[1]==s.bot[0]){
                        cout<<"the stack is filled"<<endl;
                        exit(0); 
                    }
                    //怎么边删边加
                    s.v[s.top[1]++]=0;
                } 
                break;
    }
}
//展示栈中元素   取栈顶元素  好像展示不了，如果展示的话，我就需要创建新的指针其实也挺简单的
/*
void show_stack(Dblstack &s){
    int choice;
    cout<<"which stack you want to choose(0&1)"<<endl;
    cin>>choice;
    switch(choice){
        case 0:
            int length_la=0;
            length_la = s.top[0]-s.bot[0];
            for(int i=0;i<length_la;i++){

            }
            break;
        case 1:

            break;
    }
}
*/
int main(void){
    Dblstack a;
    InitStack(a);
    Empty(a);
    Fill(a);
    go_stack(a);
    leave_stack(a);

}
//我总觉得自己这么写不对，既不是c也不是c++那些写出来有什么用？？？？？？、