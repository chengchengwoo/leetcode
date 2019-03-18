/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (50.17%)
 * Total Accepted:    306K
 * Total Submissions: 609K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
    vector<int> preorderTraversal(TreeNode* root) {
        //vector<int> res;
        //preorderTraversalRecursive(root, &res);
        //return res;
        return preorderTraversalIterative(root);
    }
    // T: O(n) S: O(n)
    void preorderTraversalRecursive(TreeNode* root, vector<int>* res) {
        if (!root) return;
        res->push_back(root->val);
        preorderTraversalRecursive(root->left, res);
        preorderTraversalRecursive(root->right, res);
    }
    // T: O(n) S: O(n)
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            root = root->right;
        }
        return res;
    }
};

