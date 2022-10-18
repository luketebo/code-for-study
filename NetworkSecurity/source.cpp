#include "windows.h"
#include "iostream"
#include "stdlib.h"
#include "fstream"
using namespace std;

int main () {
    // create the file
    ofstream oFile;
    oFile.open("c:\\Programs\\Luke.txt", ios::app);
    if(!oFile)
        cout << "error 1" << endl;
    else 
        oFile.close();
    // open the notepad
    system("notepad");
    system("pause");
    return 0;
}