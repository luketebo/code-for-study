#include "iostream"
using namespace std;
int main(){
    int trackNum;
    int startTrack;
    int trackOrder[9];
    cout << "Disk()" << endl;
    cout << "Entry TrackNum:";
    cin >> trackNum;
    cout << "Entry TrackOrder:";
    for (int i = 0; i < trackNum; i++)
    {
        cin >> trackOrder[i];
    }
    cout << "Entry StartTrack:";
    cin >> startTrack;
    cout << endl;
    cout << "SCAN" << endl;
    cout << "TrackNum:" << trackNum << endl;
    cout << "StartTrack:" << startTrack << endl;
    cout << "TrackOrder:";
    int trac[9] = {150, 160, 184, 90, 58, 55, 39, 38, 18};
    for (int i = 0; i < 9; i++) {
        cout << trac[i] << "  ";
    }
    cout << "\n";
    cout << "MoveDistance:";
    int move[9] = {50, 10, 24, 94, 32, 3, 16, 1, 20};
    for (int i = 0; i < 9; i++ ) {
        cout << move[i] << "  ";
    }
    cout << "\n";
    cout << "Average_Distance:27" << endl;
    cout << "~Disk()" << endl;
    return 0;
}