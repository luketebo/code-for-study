/**
 * @file demo.c++
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 * 读者写者问题
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <windows.h>
#include <chrono>
using namespace std;
int mtx = 1;
int wtx = 1;
std::mutex mutex;
int readcount = 0;
// 原子操作
void P(int S)
{
    while (S <= 0)
    {
        S--;
    }
}
void V(int S)
{
    S++;
}
void reader()
{
    while (true)
    {
        P(mtx);
        readcount++;
        if (readcount == 1)
        {
            P(wtx);
        }
        V(mtx);
        cout << "读" << endl;
        P(mtx);
        readcount--;
        if (readcount == 0)
        {
            V(wtx);
        }
        V(mtx);
    }
}
void writer()
{
    P(wtx);
    cout << "写" << endl;
    V(wtx);
}
int main()
{
    

    return 0;
}