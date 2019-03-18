/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (28.50%)
 * Total Accepted:    191.7K
 * Total Submissions: 670.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    // T: O(n) S: O(1)
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return -1;

        int curMin = nums[0];
        int curMax = nums[0];
        int maxNum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmpMin = nums[i] * curMin;
            int tmpMax = nums[i] * curMax;
            curMin = min({tmpMin, tmpMax, nums[i]});
            curMax = max({tmpMin, tmpMax, nums[i]});
            maxNum = max(maxNum, curMax);
        }
        return maxNum;
    }
};

