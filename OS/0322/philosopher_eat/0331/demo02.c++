/**
 * @file demo02.c++
 * @author Luke Tebo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 * philosopher eating problem
 */
#include <iostream>
#include <future>
#include <mutex>
#include <chrono>
#include <thread>
using namespace std;
std::mutex chopstick[5];
void philosopher(int arg)
{
    int i = arg;
    int left, right;
    if( i == 4){
        left = i;
        right = 0;
    }else{
        left = i;
        right = i + 1;
    }
    while(1){

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        chopstick[left].lock();
        cout<<"philosopher " << i << " fetches chopstick " << left << endl;

        // how to try lock?
        if(!chopstick[right].try_lock()){
            chopstick[left].unlock();
            continue;
        }

        cout<<"philosopher " << i << " fetches chopstick " << right << endl;
        cout<<"philosopher " << i << " is eating "<<endl;

        // sleep(2)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        chopstick[right].unlock();
        cout<<"philosopher " << i <<" release chopstick " << right << endl;
        
        chopstick[left].unlock();
        cout<<"philosopher " << i <<" release chopstick " << left << endl;
        
    }

}
int main(){
    thread thread1(philosopher,1);
    thread thread2(philosopher,2);
    thread thread3(philosopher,3);
    thread thread4(philosopher,4);
    thread thread5(philosopher,5);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    return 0;
}