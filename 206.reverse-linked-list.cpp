/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (52.61%)
 * Total Accepted:    525.5K
 * Total Submissions: 992.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
        //return iterative(head);
        return recursive(head);
    }
    // T: O(n) S: O(n)
    ListNode* recursive(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* node = recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
    // T: O(n) S: O(1)
    ListNode* iterative(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

