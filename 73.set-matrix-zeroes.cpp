/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (38.91%)
 * Total Accepted:    191.8K
 * Total Submissions: 491.9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //extraSpace(matrix);
        constSpace(matrix);
    }
    // T: O(m*n) S: O(m+n)
    void extraSpace(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // T: O(m*n) S: O(1)
    void constSpace(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool row0 = false;
        bool col0 = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                row0 = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row0) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (col0) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

