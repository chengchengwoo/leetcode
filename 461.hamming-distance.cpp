/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.01%)
 * Total Accepted:    222.4K
 * Total Submissions: 317.4K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
class Solution {
public:
    // T: O(k) S: O(1)
    // k为返回结果，即位不相同的个数
    int hammingDistance(int x, int y) {
        int total = 0;
        int n = x ^ y;
        while (n > 0) {
            ++total;
            n &= (n - 1);
        }
        return total;
    }
};

