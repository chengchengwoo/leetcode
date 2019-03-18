/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (33.83%)
 * Total Accepted:    171.9K
 * Total Submissions: 504.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        //quickSortRecursive(head, nullptr);
        head = mergeSortRecursive(head);
        return head;
    }
    // T: O(nlogn) S: O(1)
    // 从head开始，不包括end
    void quickSortRecursive(ListNode* head, ListNode* end) {
        if (head == end || head->next == end) {
            return;
        }
        // 选取head为pivot，定义两个快慢指针
        ListNode* pivot = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // 快指针遍历寻找<=pivot的节点，找到后与慢指针值交换，
        // 使得慢指针之前的节点均<=pivot，之后的都>pivot
        for (; fast != end; fast = fast->next) {
            if (fast->val <= pivot->val) {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
        }
        // 将慢指针与pivot值交换
        swap(slow->val, pivot->val);

        // 分治
        quickSortRecursive(head, slow);
        quickSortRecursive(slow->next, end);
    }
    // T: O(nlogn) S: O(1)
    ListNode* mergeSortRecursive(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        // 使用快慢指针将list均分为两份，均分后slow为中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = mergeSortRecursive(slow->next);
        slow->next = nullptr;
        ListNode* l2 = mergeSortRecursive(head);
        return mergeTwoSortedList(l1, l2);
    }
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return dummy.next;
    }
};

