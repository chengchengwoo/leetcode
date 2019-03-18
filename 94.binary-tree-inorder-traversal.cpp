/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (54.94%)
 * Total Accepted:    409.8K
 * Total Submissions: 745K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalIteratively(root, &res);
        //inorderTraversalRecursively(root, &res);
        return res;
    }
    // T: O(n) S: O(n)
    void inorderTraversalRecursively(TreeNode* root, vector<int>* res) {
        if (!root) return;
        inorderTraversalRecursively(root->left, res);
        res->push_back(root->val);
        inorderTraversalRecursively(root->right, res);
    }
    // T:O(n) S:O(n)
    void inorderTraversalIteratively(TreeNode* root, vector<int>* res) {
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            res->push_back(root->val);
            root = root->right;
        }
    }
};

