#include <iostream>
using namespace std;
int count = 10;
void test(int &count){
    count = 9;
}
int main(){
    test(count);
    cout << count << endl;
    return 0;
}