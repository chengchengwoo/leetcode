/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (63.09%)
 * Total Accepted:    112.9K
 * Total Submissions: 178.8K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
    // T: O(n) S: O(n)
    string reverseWords(string s) {
        for (int i = 0, j = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                for (int m = j, n = i - 1; m < n; ++m, --n) {
                    swap(s[m], s[n]);
                }
                j = i + 1;
            }
        }
        return s;
    }
};

