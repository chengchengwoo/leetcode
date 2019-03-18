/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (32.86%)
 * Total Accepted:    349.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //return mergeByTwo(lists);
        //return mergeByHeap(lists);
        return mergeByDivideConquer(lists);
    }
    // T: O(n*logk) S: O(k)
    // n为总的节点数量, k为链表数量
    // 使用一个最小堆维护当前头节点值最小的链表
    ListNode* mergeByHeap(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        auto cmp = [](ListNode* lhs, ListNode* rhs) {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> h(cmp);
        for (auto l : lists) {
            if (l) {
                h.push(l);
            }
        }
        while (!h.empty()) {
            ListNode* l = h.top();
            h.pop();
            if (l->next) {
                h.push(l->next);
            }
            p->next = l;
            p = p->next;
        }
        return dummy.next;
    }
    // T: O(n*logk) S: O(logk)
    // 分治，树的高度是logk，每一层是节点总数n
    ListNode* mergeByDivideConquer(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int low, int high) {
        if (low == high) {
            return lists[low];
        }
        if (low > high) {
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        ListNode* l1 = merge(lists, low, mid);
        ListNode* l2 = merge(lists, mid + 1, high);
        return mergeTwoLists(l1, l2);
    }
    // T: O(n*k) S: O(1)
    // n为总的节点数量, k为链表数量
    // 复杂度分析：
    // 假设每条链表节点数为m，则依次合并的节点数量为：
    // 2m + 3m + 4m + ... + km = k(2+k)m/2 ~= k*k*m即n*k
    ListNode* mergeByTwo(vector<ListNode*>& lists) {
        ListNode* p = nullptr;
        for (ListNode* l : lists) {
            p = mergeTwoLists(p, l);
        }
        return p;
    }
    // 辅助函数：合并两条有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
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

