/**
 * @file test.c++
 * @author Luke Tebo (luketebo.ycs@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item
{
    int id;
    float value;
    float weight;
    float v_w;
};

const int maxn = 1000;
bool isChosen[maxn];
vector<Item>item;

bool cmp(Item a,Item b)
{
    if (a.v_w > b.v_w)
        return true;
    else
        return false;
}

void Knapsack_greedy(int n,int M)
{
    int totw = 0;//记录当前重量
    for (int i = 0;i < n;i++)
    {
        if (totw + item[i].weight<=M)
        {
            isChosen[item[i].id] = true;
            totw += item[i].weight;
        }
        
    }
}



int main()
{
    int n;//物品数量
    int M;//背包最大容量
    cin >> n >> M;

    float value, weight;
    for (int i = 0;i < n;i++)
    {
        cin >> value >> weight;
        item.push_back({ i,value,weight,value / weight });//存储物品信息
    }

    sort(item.begin(), item.end(), cmp);

    Knapsack_greedy(n, M);

    for (int i = 0;i < n;i++)
    {
        if (isChosen[i])
        {
            cout <<"选择物品为："<< i+1 << " ";
        }
    }

    return 0;
}

