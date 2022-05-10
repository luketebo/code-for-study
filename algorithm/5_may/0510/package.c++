/**
 * @file package.c++
 * @author Luke Tebo(you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 0-1 背包问题 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
/* 动态规划 */
void test(){
    std::vector<int> weight = {1, 3, 4};
    std::vector<int> value = {15, 20, 30};

    int baweight = 4;
    // 二维数组
    std::vector<std::vector<int>> dp(weight.size(), std::vector<int>(baweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= baweight; j++) {
        dp[0][j] = value[0];
    }

    // weight 数组的大小， 就是物品个数
    for (int i = 1; i < weight.size(); i++) {
        for (int j = 0; j <= baweight; j++) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    std::cout << dp[weight.size() - 1][baweight] << std::endl; 
}
int main(int argc, char * argv[]){
    test();
    return 0;
}