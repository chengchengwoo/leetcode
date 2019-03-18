/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (34.79%)
 * Total Accepted:    331.5K
 * Total Submissions: 950.3K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        mergeWithoutShift(nums1, m, nums2, n);
        //mergeShift(nums1, m, nums2, n);
    }
    // T: O(m+n) S: O(1)
    void mergeWithoutShift(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n -1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
    // T: O(m+n+n*m) S: O(1)
    void mergeShift(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0, j = 0; j < n; ++i) {
            if (i == m) {
                nums1[i] = nums2[j];
                ++j;
                ++m;
            } else if (nums1[i] > nums2[j]) {
                // insert and shift array
                for (int k = m; k > i; --k) {
                    nums1[k] = nums1[k - 1];
                }
                nums1[i] = nums2[j];
                ++j;
                ++m;
            }
        }
    }
};

