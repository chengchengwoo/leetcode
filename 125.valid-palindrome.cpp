/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.16%)
 * Total Accepted:    322.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        //return isPalindromeRecursive(s, 0, s.size() - 1);
        return isPalindromeIterative(s);
    }
    // T: O(n) S: O(n)
    bool isPalindromeRecursive(const string& s, int begin, int end) {
        // ignore chars
        for (; !isalnum(s[begin]) && begin < end; ++begin);
        for (; !isalnum(s[end]) && begin < end; --end);

        int size = end - begin + 1;
        if (size < 0) return false;
        if (size == 0 || size == 1) return true;
        return tolower(s[begin]) == tolower(s[end]) && isPalindromeRecursive(s, begin + 1, end - 1);
    }
    // T: O(n) S: O(1)
    bool isPalindromeIterative(const string& s) {
        if (s.empty()) return true;
        
        for (int begin = 0, end = s.size() - 1; begin < end; ++begin, --end) {
            // ignore chars
            for (; !isalnum(s[begin]) && begin < end; ++begin);
            for (; !isalnum(s[end]) && begin < end; --end);
            if (begin < end && tolower(s[begin]) != tolower(s[end])) {
                return false;
            }
        }
        return true;
    }
};

