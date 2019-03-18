/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (41.27%)
 * Total Accepted:    293.4K
 * Total Submissions: 709.3K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //countingSort(nums);
        twoPointers(nums);
    }
    // T: O(n) S: O(1)
    void countingSort(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int num : nums) {
            if (num == 0) ++cnt0;
            else if (num == 1) ++cnt1;
            else if (num == 2) ++cnt2;
        }
        int k = 0;
        for (; cnt0 > 0; nums[k++] = 0, --cnt0);
        for (; cnt1 > 0; nums[k++] = 1, --cnt1);
        for (; cnt2 > 0; nums[k++] = 2, --cnt2);
    }
    // T: O(n) S: O(1)
    void twoPointers(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for (int mid = 0; mid <= right;) {
            if (nums[mid] == 2) {
                swap(nums[right], nums[mid]);
                --right;
            } else if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                ++left;
                ++mid;
            } else {
                ++mid;
            }
        }
    }
};

