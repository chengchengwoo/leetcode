/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (41.85%)
 * Total Accepted:    305.1K
 * Total Submissions: 726.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                ListNode* next = p->next;
                p->next = p->next->next;
                delete next;
            } else {
                p = p->next;
            }
        }

        return head;
    }
};

