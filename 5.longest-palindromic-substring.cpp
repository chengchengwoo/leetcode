/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.53%)
 * Total Accepted:    483.7K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindromeExpand(s);
    }
    // T: O(n*n) S: O(1)
    string longestPalindromeExpand(const string& s) {
        if (s.empty()) return "";
        int maxStart = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                maxStart = i - (len-1)/2;
            }
        }
        return s.substr(maxStart, maxLen);
    }
    int expand(const string& s, int i, int j) {
        for (; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j);
        // (j - 1) - (i + 1) + 1
        return j - i -1;
    }
    // TODO(add DP solution)
};

