/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.05%)
 * Total Accepted:    303K
 * Total Submissions: 569.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(&res, n);
        return res;
    }
    // T: O(4^n/sqrt(n)) S: O(n)
    // 组合数量是Catalan数，约为4^n/(n*sqrt(n))，每个组合遍历n个数，相乘得到时间复杂度
    // Catalan数的递推式为：
    // H(n) = H(0)*H(n-1) + H(1)*H(n-2) + ... + H(n-1)*H(0)，其中H(0) = H(1) = 1
    void backtracking(vector<string>* res, int n) {
        backtracking(res, "", n, n);
    }
    void backtracking(vector<string>* res, string s, int left, int right) {
        if (left == 0 && right == 0) {
            res->push_back(s);
            return;
        }
        if (left > 0) {
            backtracking(res, s + "(", left - 1, right);
        }
        if (right > left) {
            backtracking(res, s + ")", left, right - 1);
        }
    }
    // TODO DP解法
};

