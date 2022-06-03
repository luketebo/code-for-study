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
const int N = 10;
int empty = N;
int full = 0;
int mutex = 1;
std::mutex mtx;
void Producer()
{
    while (1)
    {
        int num = 0;
        mtx.lock();
        if (full != N)
        {
            cout << "Producer : product " << ++num << endl;
            full++;
            empty--;
        }
        else
        {
            cout << "Producer : product stop!!!" << endl;
        }
        mtx.unlock();
        Sleep(100);
    }
}
void Consumer()
{

    while (1)
    {
        mtx.lock();
        int num = 0;
        if (empty != N)
        {
            cout << "Consumer : consume : " << ++num << endl;
            empty++;
            full--;

        }else{
            cout << "Consumer stop!! "<<endl;
        }
        mtx.unlock();
        Sleep(99);
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