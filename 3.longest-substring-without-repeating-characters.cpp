/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (27.69%)
 * Total Accepted:    815.9K
 * Total Submissions: 2.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //return bruteForce(s);
        //return slidingWindow(s);
        return slidingWindow2(s);
    }
    // T: O(n*n) S: O(m)
    // m = charset size
    int bruteForce(const string& s) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            vector<bool> visited(256, false);
            int j = i;
            for (; j < s.size(); ++j) {
                if (visited[s[j]]) {
                    break;
                }
                visited[s[j]] = true;
            }
            if (j - i > maxLen) {
                maxLen = j - i;
            }
        }
        return maxLen;
    }
    // T: O(n) S: O(m)
    // m = charset size
    int slidingWindow(const string& s) {
        vector<bool> visited(256, false);
        int maxLen = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            for (; j < s.size(); ++j) {
                if (visited[s[j]]) {
                    break;
                }
                visited[s[j]] = true;
            }
            visited[s[i]] = false;
            maxLen = max(maxLen, j - i);
        }
        return maxLen;
    }
    // T: O(n) S: O(m)
    // m = charset size
    int slidingWindow2(const string& s) {
        vector<int> index(256, -1);
        int maxLen = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            i = max(index[s[j]] + 1, i);
            maxLen = max(maxLen, j - i + 1);
            index[s[j]] = j;
        }
        return maxLen;
    }
};

