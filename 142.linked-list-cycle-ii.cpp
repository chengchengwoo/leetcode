/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.83%)
 * Total Accepted:    197.2K
 * Total Submissions: 637K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        //return usingSet(head);
        return usingPointers(head);
    }
    // T: O(n) S: O(n)
    ListNode* usingSet(ListNode* head) {
        unordered_set<ListNode*> s;
        for (; head; head = head->next) {
            if (!s.insert(head).second) {
                return head;
            }
        }
        return nullptr;
    }
    // T: O(n) S: O(1)
    ListNode* usingPointers(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (; fast && fast->next;) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                for (ListNode* p = head; p != slow; p = p->next, slow = slow->next);
                return slow;
            }
        }
        return nullptr;
    }
};

