//作业9：试写一个算法判断字符数列是否为回文数（将一半字符入栈）
#include<iostream>
using namespace std;
#define maxsize 100;
//创建栈
typedef struct{
    char  *base;
    char  *top;
    int stacksize;
} sqstack;
//初始化
void  InitStack(sqstack &s){
    s.base = new char[100];
    if(!s.base) exit(0);
    s.top= s.base;
    s.stacksize = 100;
}
//入栈
void push(sqstack &s, char e){
    if(s.top-s.base==s.stacksize) exit(0);
    *s.top++=e;
}
void pop(sqstack &s,char &e){
    if(s.top==s.base) exit(0);
    e=*--s.top;
}
int main(void){
    char a[10];
    cout<<"input the character string"<<endl;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    
    sqstack st;
    //初始化栈
    InitStack(st);
    //让一半的数组入栈
    int i=0;
    for(; i<5; i++){
        push(st,a[i]); 
    }
    //让剩下的一半出栈，和前面的进行比较
    while(i<10){
        char ab;
        //出栈
        pop(st,ab);
        if(a[i]!=ab) {
            cout<<"the character string is not a palindromic"<<endl;
            return 0;
        }
        i++;
        
    }
    cout<<"the character string is a palindromic"<<endl;
    return 0;
}   