/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.96%)
 * Total Accepted:    356.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //return twoPass(head, n);
        return onePass(head, n);
    }
    // T: O(n) S: O(1)
    ListNode* twoPass(ListNode* head, int n) {
        int len = 0;
        for (ListNode* p = head; p; p = p->next, ++len);
        int index = len - n;
        if (index == 0) {
            ListNode* ret = head->next;
            delete head;
            return ret;
        }
        ListNode* p = head;
        for (int i = 0; i < index - 1; ++i, p = p->next);
        ListNode* next = p->next;
        p->next = p->next->next;
        delete next;
        return head;
    }
    // T: O(n) S: O(1)
    // 1. 使用dummy节点，统一头节点及后续节点逻辑
    // 2. 定义快慢指针，快指针先移动n步
    // 3. 然后快慢指针一起移动，直到快指针到末尾 
    // 4. 删除慢指针的next
    ListNode* onePass(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        ListNode* q = &dummy;
        for (; q->next && n > 0; q = q->next, --n);
        if (n != 0) {
            return dummy.next;
        }
        for (; q->next; q = q->next, p = p->next);
        ListNode* next = p->next;
        p->next = p->next->next;
        delete next;
        return dummy.next;
    }
};

