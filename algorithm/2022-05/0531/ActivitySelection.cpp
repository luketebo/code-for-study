/**
 * @file ActivitySelection.cpp
 * @author Luke Tebo (luketebo.ycs@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 * 活动安排-贪心
 * 输入： n个活动组成的集合S = (a1,a2,...,an)
 *        每个活动ai的开始时间si和结束时间fi
 * 输出：找出活动集合s的子集s',令max|s'| s.t.Vai,aj,si >= fj 或 sj >= fi
 */
#include <iostream>
#include <vector>
using namespace std;
#define MaxNumber 0x0B
vector<int> start_time(MaxNumber, 0);  // 活动开始时间
vector<int> finish_time(MaxNumber, 0); // 活动结束时间
vector<bool> activity_set(MaxNumber);  // 选择的活动
void Initialize()
{
    cout << "Entry start_time:";
    for (int i = 1; i <= MaxNumber; i++)
    {
        cin >> start_time[i]; // 输入活动开始时间
    }
    cout << "Entry finish_time:";
    for (int i = 1; i <= MaxNumber; i++)
    {
        cin >> finish_time[i]; // 输入活动结束时间
    }
}
void GreedySelector()
{
    activity_set[1] = true; // 第一个活动已安排
    int j = 1;              // 当前刚刚安排的活动
    int count = 1;          // 记录所安排的活动
    for (int i = 2; i <= MaxNumber; i++)
    {
        if (start_time[i] >= finish_time[j])
        {
            activity_set[i] = true;
            j = i;
            // cout << j << endl;
            count++;
        }
        else
            activity_set[i] = false;
    }
    cout << count << endl;
    for (int i = 1; i <= MaxNumber; i++)
    {
        cout << "activity_set[" << i << "]: " << activity_set[i] << "  ";
    }
}
int main()
{
    Initialize();
    GreedySelector();
    return 0;
}