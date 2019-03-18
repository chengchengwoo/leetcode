/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (58.92%)
 * Total Accepted:    425K
 * Total Submissions: 718.1K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //return XOR(nums);
        return usingSet(nums);
    }
    // T: O(n) S: O(1)
    int XOR(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
    // T: O(n) S: O(n)
    int usingSet(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            // 如果已存在，则删除
            auto ret = s.insert(num);
            if (!ret.second) {
                s.erase(ret.first);
            }
        }
        if (s.empty()) {
            return -1;
        }
        return *s.begin();
    }
};

