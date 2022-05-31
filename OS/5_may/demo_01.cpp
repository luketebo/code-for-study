/**
 * @file demo_01.cpp
 * @author Luke Tebo (luketebo.ycs@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 * 磁盘调度算法：
 * FCFS： 先来先服务
 * SSTF： 最短寻道时间优先
 * SCAN： 扫描磁道
 * CSCAN：循环扫描
 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define MaxNumber 0x64
int TrackNum;                              // 磁道数
int StartTrack;                            // 开始磁道
vector<int> TrackOrder(MaxNumber, 0x00);   // 初始磁道顺序
vector<int> VisitedOrder(MaxNumber, 0x00); // 被访问的磁道顺序
int Sum_Distance = 0;                      // 总寻道距离
vector<int> MoveDistance(MaxNumber, 0x00); // 每个磁道移动距离
int Average_Distance = 0;                  // 平均寻道距离
void Initialize();                         // 初始化
void Enter();                              // 输出初始数据
void Print();                              // 打印结果
int distance(int a, int b);                // 计算距离
void FCFS();                               // 先来先服务
void SSTF();                               // 最短寻道时间优先
void SCAN();                               // 扫描磁道
void CSCAN();                              // 循环扫描
void Initialize()
{
}
void Enter()
{
    cout << "Entry TrackNum:";
    cin >> TrackNum;
    cout << "Entry TrackOrder:";
    for (int i = 0; i < TrackNum; i++)
    {
        cin >> TrackOrder[i]; // 输入磁盘队列
    }
    cout << "Entry StartTrack:";
    cin >> StartTrack;
}
int distance(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}
void Print()
{
    cout << "TrackNum:" << TrackNum << endl;
    cout << "StartTrack:" << StartTrack << endl;
    cout << "TrackOrder:";
    for (int i = 0; i < TrackNum; i++)
    {
        cout << setw(4) << VisitedOrder[i];
    }
    cout << endl;
    cout << "MoveDistance:";
    for (int i = 0; i < TrackNum; i++)
    {
        cout << setw(4) << MoveDistance[i];
    }
    cout << endl;
    cout << "Sum_Distance:" << Sum_Distance << endl;
    cout << "Average_Distance:" << Average_Distance << endl;
}
void FCFS()
{
    for (int i = 0; i < TrackNum; i++)
    {
        Sum_Distance += distance(StartTrack, TrackOrder[i]);
        MoveDistance[i] = distance(StartTrack, TrackOrder[i]);
        StartTrack = TrackOrder[i];
    }
    Average_Distance = Sum_Distance / TrackNum;
}
void SSTF()
{
    int Min_Distance = 0;
    int Min_Index = 0;
    for (int i = 0; i < TrackNum; i++)
    {
        Min_Distance = distance(StartTrack, TrackOrder[i]);
        for (int j = 0; j < TrackNum; j++)
        {
            if (Min_Distance > distance(StartTrack, TrackOrder[j]))
            {
                Min_Distance = distance(StartTrack, TrackOrder[j]);
                Min_Index = j;
            }
        }
        Sum_Distance += Min_Distance;
        MoveDistance[i] = Min_Distance;
        VisitedOrder[i] = TrackOrder[Min_Index];
        StartTrack = TrackOrder[Min_Index];
        TrackOrder[Min_Index] = 0x00;
    }
    Average_Distance = Sum_Distance / TrackNum;


}
int main()
{
    Initialize();
    Enter();
    SSTF();
    Print();
    return 0;
}