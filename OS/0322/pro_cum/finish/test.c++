/**
 * @file test.c++
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-22
 *
 * @copyright Copyright (c) 2022
 *
 * 使用c++11 解决生产者消费者问题
 */
#include <bits/stdc++.h>
#include <thread> //  thread
#include <future> // std::async std::future
#include <windows.h>
#include <mutex>  // std::mutex 加锁
#include <chrono> // std::chrono::seconds()
using namespace std;
int n = 10;
std::mutex mtx;
void Producer()
{
    while(1){
    mtx.lock();
    if (n >= 10)
    {
        cout << "Producer stop!!" << endl;

        
    }
    else
    {
        n++;
        cout << "Producer: Product " << n << endl;
    }
    mtx.unlock();
    Sleep(100);

    }
}
void Consumer()
{
    while(1){
    mtx.lock();
    if (n <= 0)
    {
        cout << "Consumer stop!!!" << endl;
    }
    else
    {
        n--;
        cout << "Consumer: Consume " << n << endl;
    }
    mtx.unlock();
    Sleep(60);
    }
}
void Test_and_Set(){
    while(n < 10){
        if(n <= 0){
            cout<<"Consumer stop!!"<<endl;
        } 
    }
}
int main()
{

    thread thread1(Producer);
    thread thread2(Consumer);
    
    thread1.join();

    thread2.join();
   

    return 0;
}