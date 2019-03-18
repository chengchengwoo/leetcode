/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.42%)
 * Total Accepted:    351.4K
 * Total Submissions: 681.3K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //return counting(nums);
        return mooreVote(nums);
    }
    // T: O(n) S: O(n)
    int counting(vector<int>& nums) {
        unordered_map<int, int> counter;
        int halfSize = nums.size() / 2;
        for (int num : nums) {
            counter[num] = counter[num] + 1;
            if (counter[num] > halfSize) {
                return num;
            }
        }
        return -1;
    }
    // T: O(n) S: O(1)
    int mooreVote(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                num = nums[i];
                count = 1;
            } else if (nums[i] == num) {
                ++count;
            } else {
                --count;
            }
        }
        return num;
    }
};

