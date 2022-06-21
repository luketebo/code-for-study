/**
 * @file arrange_full.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */
/**
 * 全排列
 * 从n个不同元素中任取m（m≤n）个元素，按照一定的顺序排列起来，叫做从n个不同元素中取出m个元素的一个排列。
 * 当m=n时所有的排列情况叫全排列。
 * 公式：全排列数f(n)=n!(定义0!=1)
 * */
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

#ifndef ARRANGE_FULL_H
#define ARRANGE_FULL_H
class ARRANGE
{
public:
    // 暴力枚举
    void enumeration(char a[], int length)
    {
    }
    // 递归算法
    void Arrange_Full(char a[], int begin, int end)
    {
        int i, j;
        if (begin == end)
        {
            cout << "满足条件的排列：" << endl;
            for (i = 0; i <= end; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (j = begin; j <= end; j++)
            {
                cout << "swap(" << a[j] << "," << a[begin] << ")" << endl;
                swap(a[j], a[begin]);
                // cout << "排序" << endl;
                Arrange_Full(a, begin + 1, end); //递归调用
                cout << "swap(" << a[j] << "," << a[begin] << ")" << endl;
                swap(a[j], a[begin]);
            }
        }
    }
    int main()
    {
        cout << "算法简介： " << endl;
        cout << "全排列 \n从n个不同元素中任取m（m≤n）个元素，按照一定的顺序排列起来，叫做从n个不同元素中取出m个元素的一个排列。\n当m=n时所有的排列情况叫全排列。\n公式：全排列数f(n)=n!(定义0!=1)" << endl;
        char a[MAXSIZE] = {0};
        cout << "please input the string array:" << endl;
        cin >> a;
        int length = strlen(a);
        cout << "全排列算法" << endl;
        cout << "-----------排列后----------" << endl;
        cout << "将每一个元素与第一个元素交换" << endl;
        cout << "让之后的元素全排列" << endl;
        Arrange_Full(a, 0, length - 1);
        return 0;
    }
};
#endif