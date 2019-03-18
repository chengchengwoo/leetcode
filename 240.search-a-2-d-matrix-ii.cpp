/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.23%)
 * Total Accepted:    160.3K
 * Total Submissions: 398.5K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
    // T: O(m+n) S: O(1)
    // 从左下角开始搜索，
    // 如果等于target则返回，
    // 如果大于target，则当前行都可以排除掉，row_index递减，
    // 如果小于target，则当前列都可以排除掉，col_index递增
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        for (int row = m - 1, col = 0; row >= 0 && col < n;) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                ++col;
            } else {
                --row;
            }
        }
        return false;
    }
};
