/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.60%)
 * Total Accepted:    59K
 * Total Submissions: 199.1K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //return twoPass(nums);
        return onePass(nums);
    }
    // T: O(n) S: O(1)
    int twoPass(vector<int>& nums) {
        // 找到左侧第一个非递增元素
        int left = 0;
        for (; left < nums.size() - 1 && nums[left + 1] >= nums[left]; ++left);
        if (left == nums.size() - 1) {
            return 0;
        }
        // 找到右侧第一个非递增元素
        int right = nums.size() - 1;
        for (; right > 0 && nums[right] >= nums[right - 1]; --right);
        // 在中间区域找到最大值和最小值
        int max_in_center = INT_MIN;
        int min_in_center = INT_MAX;
        for (int i = left; i <= right; ++i) {
            max_in_center = max(max_in_center, nums[i]);
            min_in_center = min(min_in_center, nums[i]);
        }
        // 分别在左侧区域及右侧区域找到最小值及最大值插入位置
        for (; left >= 0 && nums[left] > min_in_center; --left);
        for (; right < nums.size() && nums[right] < max_in_center; ++right);
        return max(right - left - 1, 0);
    }
    // T: O(n) S: O(1)
    int onePass(vector<int>& nums) {
        // 初始化为0和-1，保证全部有序时，返回0
        int i = 0;
        int j = -1;
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int k = 0; k < nums.size(); ++k) {
            max_val = max(max_val, nums[k]);
            if (max_val != nums[k]) {
                j = k;
            }
            int p = nums.size() - k - 1;
            min_val = min(min_val, nums[p]);
            if (min_val != nums[p]) {
                i = p;
            }
        }
        return j - i + 1;
    }
};

