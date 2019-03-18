/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.50%)
 * Total Accepted:    295.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        //return bruteForce(x, n);
        return fastPow(x, n);
    }
    // T: O(logn) S: O(1)
    // x^13 = x^8 * x^4 * x
    // 13 = 0b1101
    double fastPow(double x, int n) {
        // 转为long型，是防止n为最小值-2^31时，取绝对值会溢出
        // 32-bit最小值的表示为 0x80000000对应的绝对值为0x10000000
        long N = abs(static_cast<long>(n));
        double ret = 1;
        while (N != 0) {
            if (N & 1 == 1) {
                ret *= x;
            }
            x *= x;
            N >>= 1;
        }
        return n < 0 ? 1 / ret : ret;
    }
    // T: O(n) S: O(1)
    // Time Limit Exceeded
    double bruteForce(double x, int n) {
        double ret = 1;
        // 转为long型，是防止n为最小值-2^31时，取绝对值会溢出
        // 32-bit最小值的表示为 0x80000000对应的绝对值为0x10000000
        long N = abs(static_cast<long>(n));
        for (long i = 0; i < N; ++i) {
            ret *= x;
        }
        return n < 0 ? 1 / ret : ret;
    }
};

