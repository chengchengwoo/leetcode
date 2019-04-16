/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.27%)
 * Total Accepted:    233.3K
 * Total Submissions: 660.1K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //return usingArray(head);
        //return usingStack(head);
        return reverseList(head);
    }
    // T: O(n) S: O(n)
    bool usingArray(ListNode* head) {
        vector<ListNode*> arr;
        while (head) {
            arr.push_back(head);
            head = head->next;
        }
        for (int i = 0, j = arr.size() - 1; i < j; ++i, --j) {
            if (arr[i]->val != arr[j]->val) {
                return false;
            }
        }
        return true;
    }
    // T: O(n) S: O(n)
    bool usingStack(ListNode* head) {
        stack<int> st;
        for (ListNode* p = head; p; p = p->next) {
            st.push(p->val);
        }
        for (ListNode* p = head; p; p = p->next) {
            if (p->val != st.top()) {
                return false;
            }
            st.pop();
        }
        return true;
    }
    // T: O(n) S: O(1)
    bool reverseList(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p; p = p->next, ++len);

        ListNode* prev = nullptr;
        ListNode* cur = head;
        int halfLen = len / 2;
        for (int i = 0; i < halfLen; ++i) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // 注意：奇数长度时，需要右移一位
        if (len % 2 == 1) {
            cur = cur->next;
        }

        for (; prev && cur; prev = prev->next, cur = cur->next) {
            if (prev->val != cur->val) {
                return false;
            }
        }
        return true;
    }
};

