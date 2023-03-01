/**
 * @file subsquence.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
void LCS(std::vector<int>& num_01, std::vector<int>& num_02){
    int len_01 = num_01.size();
    int len_02 = num_02.size();
    std::vector<std::vector<int>> dp(len_01 + 1, std::vector<int>(len_02 + 1, 0));
    for(int i = 1; i <= len_01; i++){
        for(int j = 1; j <= len_02; j++){
            if(num_01[i - 1] == num_02[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::cout << dp[len_01][len_02] << std::endl;
}
int main(){
    std::vector<int> num_01 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> num_02 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LCS(num_01, num_02);
    return 0;
}