/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.01%)
 * Total Accepted:    216.9K
 * Total Submissions: 721.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    // T: O(n) S: O(1)
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        // 从右往左找到第一个递减的元素位置p
        int p = nums.size() - 2;
        for (; p >= 0; --p) {
            if (nums[p] < nums[p + 1]) {
                break;
            }
        }
        // 如果存在该元素，则在从右往左的非递减元素中找到第一个大于该元素的元素，并交换
        if (p >= 0) {
            for (int i = nums.size() - 1; i > p; --i) {
                if (nums[i] > nums[p]) {
                    swap(nums[i], nums[p]);
                    break;
                }
            }
        }
        // 最后，将(p, nums.size() - 1]由递减改为递增
        for (int i = p + 1, j = nums.size() - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
};

