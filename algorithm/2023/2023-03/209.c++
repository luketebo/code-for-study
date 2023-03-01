#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[] = {2, 3, 1, 2, 4, 1, 3};
    int b[6] = {0};
    int c[6] = {INT32_MAX};
    int _target = 0;
    int target = 7;
    for (int i = 0; i < 6; i++) {
        _target = a[i];
        for (int j = i + 1; j < 6; j++) {
            _target = _target + a[j];
            if (target < _target) {
                c[i] = j - i + 1;
                int tempMin = INT32_MAX - 1;
                for (int i = 0; i < 6; i++) {
                    if (tempMin > c[i]) {
                        tempMin = c[i];
                    }
                }
                b[i] = tempMin;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << b[i] << endl;
    }
    return 0;
}