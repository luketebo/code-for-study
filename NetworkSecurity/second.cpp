#include <iostream>
#include "stdlib.h"
#include <windows.h>
using namespace std;

// argc 个数  argv 具体参数
int main(int argc, char *argv[])
{
    cout << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    return 0;
}