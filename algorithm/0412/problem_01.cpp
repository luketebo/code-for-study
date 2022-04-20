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
#include <vector>
using namespace std;
// 计算非空子集合数
int cal_assemble(int input){
    int out = 0;
    for(int i = 1; i < input; i++){
        out *= 2;
    }
    out -= 1; 
    return out;
}
int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    int assemble = cal_assemble(n);
    fout << assemble << endl;
    fin.close();
    return 0;

}