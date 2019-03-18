/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.84%)
 * Total Accepted:    238.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        //return backtracking(s);
        //return DP(s);
        return DPO1(s);
    }
    // T: very large
    int backtracking(const string& s) {
        int count = 0;
        backtracking(s, 0, &count);
        return count;
    }
    void backtracking(const string& s, int index, int* count) {
        if (index == s.size()) {
            ++(*count);
            return;
        }
        if (s[index] == '0') {
            return;
        }
        if (index < s.size() - 1) {
            if (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')) {
                backtracking(s, index + 2, count);
            }
        }
        backtracking(s, index + 1, count);
    }
    // T: O(n) S: O(n)
    int DP(const string& s) {
        if (s.empty()) return 0;
        vector<int> d(s.size() + 1, 0);
        d[0] = 1;
        d[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.size(); ++i) {
            if (s[i - 1] != '0') {
                d[i] += d[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                d[i] += d[i - 2];
            }
        }
        return d[s.size()];
    }
    // T: O(n) S: O(1)
    int DPO1(const string& s) {
        if (s.empty()) return 0;
        int first = 1;
        int second = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.size(); ++i) {
            int cur = 0;
            if (s[i - 1] != '0') {
                cur += second;
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                cur += first;
            }
            first = second;
            second = cur;
        }
        return second;
    }
};

