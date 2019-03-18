/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (55.76%)
 * Total Accepted:    84.4K
 * Total Submissions: 151.2K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int countSubstrings(string s) {
        return countSubstringsExpand(s);
        //return countSubstringsDP(s);
    }
    // T: O(n*n) S: O(1)
    int countSubstringsExpand(const string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += expand(s, i, i);
            count += expand(s, i, i + 1);
        }
        return count;
    }
    int expand(const string& s, int i, int j) {
        int count = 0;
        for (; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j, ++count);
        return count;
    }
    // T: O(n*n) S: O(n*n)
    int countSubstringsDP(const string& s) {
        int count = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (i == j || (s[i] == s[j] && (j - i == 1 || dp[i+1][j-1]))) {
                    dp[i][j] = true;
                    ++count;
                }
            }
        }
        return count;
    }
};

