/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (35.20%)
 * Total Accepted:    209.3K
 * Total Submissions: 592.5K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
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
    // T: O(n) S: O(1)
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next = head;
        while (p->next) {
            if (p->next->val == val) {
                ListNode* next = p->next;
                p->next = p->next->next;
                delete next;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};

