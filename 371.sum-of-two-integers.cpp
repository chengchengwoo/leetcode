/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.25%)
 * Total Accepted:    126.7K
 * Total Submissions: 247.7K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        return iterative(a, b);
    }
    // T: O(m) S: O(m)
    int recursive(int a, int b) {
        if (b == 0) {
            return a;
        }
        return recursive(a ^ b, (a & b) << 1);
    }
    // T: O(m) S: O(1)
    // TODO 未AC，提示runtime error
    // m为整数位数
    int iterative(int a, int b) {
        while (b != 0) {
            // 异或取和
            int sum = a ^ b;
            // 取进位
            int carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};

