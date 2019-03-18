/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.56%)
 * Total Accepted:    425.4K
 * Total Submissions: 793K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //return moveZeroesSwap(nums);
        return moveZeroesAssign(nums);
    }
    // T: O(n) S: O(1)
    void moveZeroesSwap(vector<int>& nums) {
        for (int slow = 0, fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                ++slow;
            }
        }
    }
    // T: O(n) S: O(1)
    void moveZeroesAssign(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        for (; slow < nums.size(); ++slow) {
            nums[slow] = 0;
        }
    }
};

