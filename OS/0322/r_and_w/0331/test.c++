/**
 * @file test.c++
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 * 读者写者
 */
#include <iostream>
#include <future>
#include <mutex>
#include <chrono>
#include <windows.h>
using namespace std;
std::mutex wtx;    // 读写互斥锁
std::mutex rtx;    // 读读互斥锁
int readcount = 0; // 监控读者数量
void reader()
{
    while (true)
    {
        rtx.lock(); // 上锁
        if (readcount == 0)
        { // 如果是第一个读者,把书上锁
            wtx.lock();
        }
        readcount++;
        rtx.unlock();
        cout << "reader is reading " << endl;

        rtx.lock(); // 上锁
        readcount--;
        if (readcount == 0)
        { // 如果是最后一个读者
            wtx.unlock();
        }
        cout << "readcount :" << readcount << endl;
        rtx.unlock();
        Sleep(100);
    }
}
void writer()
{
    while (true)
    {
        wtx.lock();
        cout << "the writer is writing " << endl;
        wtx.unlock();
        Sleep(100);
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
