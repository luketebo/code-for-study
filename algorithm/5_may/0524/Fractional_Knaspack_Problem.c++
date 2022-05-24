/**
 * @file Fractional_Knapsack_Problem.c++
 * @author Luke Tebo (luketebo.ycs@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 * 输入： n个物品组成的集合O, 每个物品有两个属性vi 和 pi, 分别表示体积和价格
 *        背包容量为C
 * 输出： 背包中物品的最大价值
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Fractional_Knapsack_Problem
{
private:
    /* data */
public:
    Fractional_Knapsack_Problem(/* args */);
    ~Fractional_Knapsack_Problem();
    void knapsack(vector<float> &v, vector<float> &p, int c);
};

Fractional_Knapsack_Problem::Fractional_Knapsack_Problem(/* args */)
{
}

Fractional_Knapsack_Problem::~Fractional_Knapsack_Problem()
{
}

void Fractional_Knapsack_Problem::knapsack(vector<float> &v, vector<float> &p, int c)
{
    // v : 体积
    // p : 价格  都是有序的(假设)
    // c : 背包容量

    int size = v.size();
    int result = 0;              // 背包中物品的最大价值
    vector<float> average(5, 0); // 分数

    for (int i = 0; i < average.size(); i++)
    {
        average.push_back(v[i] / p[i]);
    }
    for (int i = 0; i < average.size(); i++)
    {
        cout << average[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (v[i] <= c)
        {
            result += p[i];
            c -= v[i];
        }
        else
        {
            result += p[i] * c / v[i];
            c = 0;
        }
    }
    cout << result << endl;
}
int main()
{
    vector<float> v = {5, 4, 3, 2, 1}; // 体积
    vector<float> p = {1, 2, 3, 4, 5}; // 价格
    Fractional_Knapsack_Problem f;
    f.knapsack(v, p, 5);
    return 0;
}
