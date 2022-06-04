/**
 * @file demo_02.cpp
 * @author Luke Tebo (luketebo.ycs@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-04
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
class Disk
{
private:
    int TrackNum;             // 磁道数
    int StartTrack;           // 开始磁道
    vector<int> TrackOrder;   // 初始磁道顺序
    vector<int> VisitedOrder; // 被访问的磁道顺序
    int Sum_Distance;         // 总寻道距离
    vector<int> MoveDistance; // 每个磁道移动距离
    vector<bool> IsVisited;   // 是否被访问
    int Average_Distance;     // 平均寻道距离
public:
    Disk();
    ~Disk();
    void Initialize();          // 初始化
    void Enter();               // 输入初始数据
    void Print();               // 打印结果
    int Distance(int a, int b); // 计算距离
    void FCFS();                // 先来先服务
    void SSTF();                // 最短寻道时间优先
    void SCAN();                // 扫描磁道
    void CSCAN();               // 循环扫描
};