#include "disk.h"
#include <iostream>
using namespace std;
int main(){
    Disk disk;
    disk.Initialize();
    disk.Enter();
    disk.Print();
    disk.FCFS();
    disk.Print();
    // disk.SSTF();
    // disk.Print();
    // disk.SCAN();
    // disk.Print();
    // disk.CSCAN();
    // disk.Print();
    return 0;
}