/**
 * @file subarray.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-26
 *
 * @copyright Copyright (c) 2022
 *
 *  最大连续子数组问题
 * 输入：给定一个数组X[1,..,n], 对于任意一堆数组下表为l,r的非空子数组, 其和为X[l]+X[l+1]+...+X[r]
 * 输出：求最大的连续子数组的和
 * 输入： 1, 2, 3
 * 输出： 6
 * 输入：-1, 0, 1
 * 输出： 1
 */
#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
private:
public:
    // 暴力解法  获取每一个结果
    int maxSubArray(std::vector<int> &nums)
    {
        int len = nums.size();
        // int max_sum = nums[0];
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                int temp = 0;
                for (int k = i; k <= j; k++)
                {
                    temp += nums[k];
                }
                if (temp > sum)
                { // 取每一次循环的最大值
                    sum = temp;
                }
            }
        }
        printf("%d\n", sum);
        return sum;
    }
    // 分治法
    int maxSubArray_divide(std::vector<int> &nums, int left, int right)
    {
        int len = nums.size();
        return maxSubArray_divide(nums, 0, len - 1);
    }
    // 动态规划 问题嵌套 -2, 11, -4, 13, -5, -2
    int maxSubArray_dp(std::vector<int> &nums)
    {
        // 1. 确定dp数组含义  确定dp[i] 存放 nums[i] 的最大连续子数组和
        // 2. 确定状态转移方程   dp[i] = max(dp[i - 1] + a[i], a[i])  要不要添加a[i] 这个值
        // 3. 初始化 dp[0] = a[0]
        int len = nums.size();
        int sum = nums[0];
        std::vector<int> dp(len + 1, 0); // 初始化dp数组
        dp[0] = nums[0];
        // 4. 进行遍历
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j < len; j++) {
                dp[i] = std::max(dp[i - 1] + nums[j], nums[j]);
            }
            // dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > sum)
            {
                sum = dp[i];
            }
        }
        // 5. 打印dp数组 18 20 9 13 -5 -2
        for (int i = 0; i < len; i++)
        {
            std::cout << dp[i] << " ";
        }
        std::cout << std::endl;
        std::cout << sum << std::endl;
        return sum;
    }
};
int main()
{

    std::vector<int> nums{-2, 11, -4, 13, -5, -2};
    Solution s;
    // int ac = s.maxSubArray_dp(nums);
    s.maxSubArray(nums);
    return 0;
}