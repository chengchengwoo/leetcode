/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (40.16%)
 * Total Accepted:    200.4K
 * Total Submissions: 497.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //return DP(nums);
        return byTails(nums);
    }
    // T: O(n^2) S: O(n)
    int DP(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // dp[i]代表[0, i]区间内，最长连续子序列。
        // 状态转移方程为：
        // dp[i] = max([dp[j] + 1 if nums[i] > nums[j] else 1 for j in range(0, i)])
        // 然后取dp中的最大值即可
        vector<int> dp(nums.size());
        dp[0] = 1;
        int max_val = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // 注意是nums[i] > nums[j]，因为要递增
                dp[i] = max(dp[i], (nums[i] > nums[j]) ? (dp[j] + 1) : 1);
            }
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
    // T: O(nlogn) S: O(n)
    int byTails(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // tails[i]代表长度为i+1的所有连续子序列中尾部元素最小的那个元素的值，
        // 因为尾部元素越小，后续连续子序列才可能更长，因此只要记录最小的那个元素值即可。
        // 显然tails是递增有序的，只需要遍历nums，然后通过二分在tails中找到插入位置即可。
        // 最后返回tails的长度即为最长连续子序列。
        // 参考 
        vector<int> tails;
        for (int num : nums) {
            // 通过二分找到第一个>=num的元素位置
            auto it = lower_bound(tails.begin(), tails.end(), num);
            // num比tails中所有元素都大
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
};

