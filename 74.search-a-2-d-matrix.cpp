/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.66%)
 * Total Accepted:    206.9K
 * Total Submissions: 596.7K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    // T: O(logn) S: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t m = matrix.size();
        if (m == 0) return false;
        size_t n = matrix[0].size();
        if (n == 0) return false;
        size_t t = m * n;

        int left = 0;
        int right = t - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid/n][mid%n];
            if (mid_val == target) return true;
            if (mid_val > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};

