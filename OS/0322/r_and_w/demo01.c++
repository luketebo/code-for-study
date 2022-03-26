/**
 * @file demo01.c++
 * @author Luke Tebo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 * 读者和写者
 */
#include<iostream>
#include<thread>
#include<future>
#include<windows.h>
#include<mutex>
#include<chrono>
using namespace std;
int wtx = 1;  // 读写互斥
int rtx = 1;  // 读读互斥
int Readcount = 0; // 监控读进程数量

std::mutex mtx;
// std::mutex wtx;
// std::mutex rtx;
void reader(){
    while(1){
        mtx.lock();
        if(wtx && rtx){
            Readcount++;
            wtx = 0;
            rtx = 0;
            cout<<"Reader is reading"<<endl;
            // 执行等待
           
        }else if(wtx || rtx){
            cout<<"Reader is waiting"<<endl;
            // 执行唤醒
        }
        mtx.unlock();
        Sleep(100);
    }
}
void writer(){
    while(1){
        mtx.lock();
        if(wtx == 0){
            cout<<"Writer is writing"<<endl;
            wtx = 1;
            rtx = 1;
            // 执行等待
        }else {
            cout<<"Writer is waiting"<<endl;
            // 执行唤醒
        }
        mtx.unlock();
        Sleep(100);
    }
}
int main(){
    thread thread1(reader);
    thread thread2(writer);

    thread1.join();
    thread2.join();

    return 0;
}