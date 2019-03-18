/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (56.98%)
 * Total Accepted:    48.8K
 * Total Submissions: 85.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a sorted array consisting of only integers where every element appears
 * twice except for one element which appears once. Find this single element
 * that appears only once. 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * 
 * Note:
 * Your solution should run in O(log n) time and O(1) space.
 * 
 * 
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //return XOR(nums);
        return binarySearch(nums);
    }
    // T: O(logn) S: O(1)
    int binarySearch(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // 当前mid是成对数右侧，则将mid移动到成对数左侧
            if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                --mid;
                // 当前mid已经是成对数左侧，不做处理
            } else if (mid + 1 < nums.size() && nums[mid + 1] == nums[mid]) {
                ;
            } else {
                // 当前mid旁边没有相同的数，则返回
                return nums[mid];
            }
            // 如果mid与low之间是偶数个，则[low, mid)区间的数都是成对的，
            // 在当前成对数的右侧继续寻找（mid右移2位）
            if ((mid - low) % 2 == 0) {
                low = mid + 2;
            } else {
                // 否则，在mid左侧寻找
                high = mid - 1;
            }
        }
        return -1;
    }
    // T: O(n) S: O(1)
    int XOR(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

