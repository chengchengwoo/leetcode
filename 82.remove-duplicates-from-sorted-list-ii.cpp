/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (32.14%)
 * Total Accepted:    170.3K
 * Total Submissions: 527.6K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        //return useMap(head);
        return withoutExtraSpace(head);
    }
    // T: O(n) S: O(1)
    ListNode* withoutExtraSpace(ListNode* head) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next = head;
        ListNode* prev = p;
        p = p->next;
        while (p) {
            // 删除至重复节点的最后一个节点
            while (p->next && p->val == p->next->val) {
                ListNode* next = p->next;
                delete p;
                p = next;
            }
            // 若不相等，则删除剩余的一个重复节点
            if (prev->next != p) {
                prev->next = p->next;
                delete p;
            } else {
                prev = prev->next;
            }
            p = prev->next;
        }
        return dummy.next;
    }
    // T: O(n) S: O(n)
    ListNode* useMap(ListNode* head) {
        unordered_map<int, int> mp;
        for (ListNode* p = head; p; p = p->next) {
            ++mp[p->val];
        }

        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next = head;
        while (p && p->next) {
            if (mp[p->next->val] > 1) {
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

