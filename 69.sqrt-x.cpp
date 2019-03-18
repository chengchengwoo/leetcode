/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.62%)
 * Total Accepted:    336.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        //return bruteForce(x);
        //return binarySearch(x);
        return newtonMethod(x);
    }
    // T: O(logn) S: O(1)
    int binarySearch(int x) {
        // 防止溢出，转为long
        long low = 0;
        long high = static_cast<long>(x);
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long mid2 = mid * mid;
            if (mid2 == x) {
                return mid;
            } else if (mid2 < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return static_cast<int>(high);
    }
    // T: O(logn) S: O(1)
    // https://en.wikipedia.org/wiki/Newton%27s_method#Square_root_of_a_number
    int newtonMethod(int x) {
        long X = static_cast<long>(x);
        long n = X;
        while (n * n > X) {
            n = (n + X / n) / 2;
        }
        return n;
    }
    // T: O(n) S: O(1)
    int bruteForce(int x) {
        long X = static_cast<long>(x);
        long i = 1;
        for (; i * i <= X; ++i);
        return i - 1;
    }
};

