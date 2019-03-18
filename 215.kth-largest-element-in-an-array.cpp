/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (45.85%)
 * Total Accepted:    333.6K
 * Total Submissions: 720.5K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //return bySort(nums, k);
        return minHeap(nums, k);
    }
    // T: O(nlogk) S: O(k)
    int minHeap(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mh;
        for (int num : nums) {
            if (mh.size() < k) {
                mh.push(num);
            } else if (num > mh.top()) {
                mh.pop();
                mh.push(num);
            }
        }
        return mh.top();
    }
    // T: O(nlogn) S: O(1)
    int bySort(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        // partition
        // 使用nums[low]作为支点，然后使用快慢两个游标，
        // [low, slow]区间<=pivot，fast游标用于遍历nums，找到<=pivot的元素
        // 最后将slow与low交换，完成partition
        int pivot = nums[low];
        int slow = low;
        for (int fast = low + 1; fast <= high; ++fast) {
            if (nums[fast] <= pivot) {
                ++slow;
                swap(nums[fast], nums[slow]);
            }
        }
        swap(nums[low], nums[slow]);
        // 递归
        quickSort(nums, low, slow - 1);
        quickSort(nums, slow + 1, high);
    }
};

