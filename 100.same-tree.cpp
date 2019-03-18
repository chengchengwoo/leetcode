/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (49.36%)
 * Total Accepted:    348.7K
 * Total Submissions: 706.1K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 * 
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 * 
 * Example 1:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * Output: false
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeIteratively(p, q);
    }
    // T: O(n) S: O(n)
    bool isSameTreeRecursively(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return isSameTreeRecursively(s->left, t->left) && isSameTreeRecursively(s->right, t->right);
    }
    // T: O(n) S: O(n)
    bool isSameTreeIteratively(TreeNode* s, TreeNode* t) {
        std::stack<TreeNode*> st;
        st.push(s); st.push(t);

        while (!st.empty()) {
            s = st.top(); st.pop();
            t = st.top(); st.pop();

            if (!s && !t) continue;
            if (!s || !t) return false;
            if (s->val != t->val) return false;
            st.push(s->left); st.push(t->left);
            st.push(s->right); st.push(t->right);
        }
        return true;
    }
};

