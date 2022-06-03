/**
 * @file test.c++
 * @author Luke Tebo (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * 简简单单写个二分查找
 * 时间复杂度：O(logN)
 * 空间复杂度：O(1)
 */
#include <iostream>
#include <vector>
class Solution {
    public:
        int search(std::vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return -1;
        }
};
