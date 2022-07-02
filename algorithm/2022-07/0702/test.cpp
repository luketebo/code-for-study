#include "iostream"
#include "ctime"
using namespace std;
int q(int n, int m) {
    if (n == 1 || m == 1){
        return 1;
    }else if (n > m) {
        return q(n - m, m) + q(n, m - 1);
    }else if (n < m) {
        return q(n, n);
    }else {
        return 1 + q(n, n - 1);
    }
}
int main() {
    double start, stop, dur;
    start = clock();
    int a = 6;
    cout << q(6, 6);
    dur = stop - start;
    cout << start << endl;
    stop = clock();
    cout << stop << endl;
    cout << "\n用时: " << dur << "毫秒\n";
    return 0;
}