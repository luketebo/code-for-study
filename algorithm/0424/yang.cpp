/**
 * @file yang.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-24
 *
 * @copyright Copyright (c) 2022
 *
 * 最长公共序列问题
 */
#include <iostream>
#include <vector>
#include <algorithm>
// 最长公共序列
void LCS(std::vector<int> &num_01, std::vector<int> &num_02)
{
    int len_01 = num_01.size();
    int len_02 = num_02.size();
    // 预判断
    if (len_01 == 0 || len_02 == 0){
        std::cout << "0" << std::endl;
    }
    // 1. 确定dp数组    dp[i][j] 存放num_01[i] 和 num_02[j] 的最长公共序列得值
    std::vector<std::vector<int>> dp(len_01 + 1, std::vector<int>(len_02 + 1, 0)); // 高级初始化
    // 2. 确定状态转移方程 
    //  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])  // 不放 Xi, Yi
    //  dp[i][j] = dp[i - 1][j - 1] + 1             // 放 Xi, Yi
    // 3. 初始化
    // 4. 遍历
    for (int i = 1; i <= len_01; i++){
        for(int j = 1; j <= len_02; j++){
            if(num_01[i - 1] == num_02[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::cout << len_01 << " " << len_02 << std::endl;
    std::cout << dp[len_01][len_02] << std::endl;
    // 5. 打印数组 
}
int main()
{
    std::vector<int> num_01 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> num_02 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LCS(num_01, num_02);
    return 0;
}