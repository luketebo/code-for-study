/**
 * @file demo01.c++
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 *
 *  读者写者问题
 */
#include <bits/stdc++.h>
#include <thread>
#include <future>
#include <mutex>
#include <windows.h>
#include <chrono>
#include <condition_variable>
using namespace std;

int wtx = 1; // 读写互斥
int rtx = 1; // 读读互斥
int mutex = 1;
int readcount = 0;                // 监控读进程数量
// std::mutex wtx;                   // 读写互斥
std::mutex mtx;                   // 互斥信号量
std::condition_variable_any cond; // 条件变量
void reader()
{
    while (true)
    {
        // 检测互斥
        mtx.lock();
        // cond.notify_all();
        readcount++;
        if (wtx == 0)
        {
            // wait 
            cout << "reader is waiting" << endl;
            cond.wait(mtx);
        }
        else
        {
            cout << "reader is reading " << endl;
            readcount--;
            cond.notify_all();
        }
        mtx.unlock();
        cond.notify_all();
        // Sleep(100);
    }
}
void writer()
{
    while (true)
    {
        mtx.lock();
        if (wtx == 1)
        {
            cout << "writer is writing " << endl;
            wtx = 0;
        }
        else
        {
            // 让当前进程等待
            cout << "writer is waiting" << endl;
            cond.wait(mtx);
        }
        mtx.unlock();
        cond.notify_all();
        // Sleep(100);  // 毫秒
    }
}
int main()
{
    thread thread1(reader);
    thread thread2(writer);

    thread1.join();
    thread2.join();

    return 0;
}