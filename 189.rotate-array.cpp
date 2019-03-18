/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (28.85%)
 * Total Accepted:    271.1K
 * Total Submissions: 931.9K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        rotate3times(nums, k);
    }
    // T: O(n) S: O(1)
    // rotate三次，第一次左半部分，第二次右半部分，第三次整体
    void rotate3times(vector<int>& nums, int k) {
        // 注意处理循环rotate
        k = k % nums.size();
        rotateRange(nums, 0, nums.size() - k - 1);
        rotateRange(nums, nums.size() - k, nums.size() - 1);
        rotateRange(nums, 0, nums.size() - 1);
    }
    void rotateRange(vector<int>& nums, int low, int high) {
        // 注意判断边界
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        for (; low <= mid; ++low, --high) {
            swap(nums[low], nums[high]);
        }
    }
};

