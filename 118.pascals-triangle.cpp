/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (44.46%)
 * Total Accepted:    230.5K
 * Total Submissions: 516K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    // T: O(n * n) S: O(1)
    // 1. 遍历每一行，将该行都填充为1
    // 2. 将该行除首尾外的元素，使用前一行对应元素求和填充
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) return res;

        for (int i = 1; i <= numRows; ++i) {
            vector<int> row(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                const auto& prev = res[res.size() - 1];
                row[j] = prev[j - 1] + prev[j];
            }
            res.push_back(row);
        }
        return res;
    }
};

