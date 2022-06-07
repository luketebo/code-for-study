#include <iostream>
using namespace std;
#define MAXSIZE 100
void BFS(){
    int dist[MAXSIZE];

}
int main() {

    int arr[MAXSIZE][MAXSIZE];
    int point, side;

    cout << "input the point and side" << endl;
    cin >> point;
    cin >> side;

    for (int i = 0; i < point; i++ ) {
        for (int j = 0; j < point; j++) {
            if (i == j) {
                arr[i][j] = 0;
            }else {
                arr[i][j] = INT16_MAX;
            }
        }
    }

    cout << "please input the array" << endl;
    for (int i = 0; i < side; i++ ) {
        int x, y, z;
        cin >> x;
        cin >> y;
        cin >> z;
        arr[x][y] = z;
    }

    for (int i = 0; i < point; i++ ) {
        for (int j = 0; j < point; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}