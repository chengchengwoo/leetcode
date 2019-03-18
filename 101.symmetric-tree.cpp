/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.65%)
 * Total Accepted:    358.5K
 * Total Submissions: 840K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetricIteratively(root);
    }
    // recursively
    // T: O(n) S: O(n)
    bool isSymmetricRecursive(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSymmetricRecursive(s->left, t->right) && isSymmetricRecursive(s->right, t->left);
    }
    // iteratively
    // T: O(n) S: O(n)
    bool isSymmetricIteratively(TreeNode* root) {
        std::stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        
        while (!st.empty()) {
            TreeNode* s = st.top();
            st.pop();
            TreeNode* t = st.top();
            st.pop();
            
            if (!s && !t) {
                continue;
            }
            if (!s || !t) {
                return false;
            }
            if (s->val != t->val) {
                return false;
            }
            st.push(s->left);
            st.push(t->right);
            st.push(s->right);
            st.push(t->left);
        }
        return true;
    }
};

