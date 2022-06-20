/**
 * @file problem_01.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-18
 *
 * @copyright Copyright (c) 2022
 *
 * 集合划分问题：
 * 问题描述：n个元素的集合{1,2,...,n}可以划分为若干非空子集，例如，当n=4时，可以划分为15个不同的非空子集
 * 算法设计：给定正整数n，计算n个元素的集合{1,2,...,n}可以划分为若干非空子集的个数
 * 数据输入：由文件input.txt提供输入数据，文件的第一行是元素个数n，第二行是n个元素的集合
 * 结果输出：将计算出的不同的非空子集数输出到文件output.txt中
 * input.txt        output.txt
 *      5               52
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
// 计算非空集合
int F(int n, int m)
{
    if (n <= 2)
        return 1;
    if (m == 1 || n == m)
        return 1;
    else
        return F(n - 1, m - 1) + m * F(n - 1, m);
}
int main()
{
    int n;
    char end;
    int result = 0;
    // cout<<"请输入正整数n=";
    // cin>>n;
    ifstream fin("input.txt", ios::in);
    if (!fin)
    {
        cout << "文件打开失败！" << endl;
        return 0;
    }
    char buf[1024] = {0};
    while (fin >> buf)
    {
        cout << buf << endl;
    }
    // int n = (int) buf;
   
    n = atoi(buf);

    ofstream fout("output.txt", ios::out);
    if (!fout)
    {
        cout << "文件打开失败！" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        result = result + F(n, i);
    }
    fout << result << endl;
    cout << n << "个元素可划分的非空集合有" << result << "个" << endl;
    fout.close();
    fin.close();
    return 0;
}