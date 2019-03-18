/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (56.94%)
 * Total Accepted:    300K
 * Total Submissions: 526.2K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
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
    TreeNode* invertTree(TreeNode* root) {
        // return invertTreeRecursive(root);
        // return invertTreeIterative(root);
        return invertTreeIterative2(root);
    }
    // T: O(n) S: O(n)
    TreeNode* invertTreeRecursive(TreeNode* root) {
        if (!root) return root;
        std::swap(root->left, root->right);
        invertTreeRecursive(root->left);
        invertTreeRecursive(root->right);
        return root;
    }
    // using stack, T: O(n) S: O(n)
    TreeNode* invertTreeIterative(TreeNode* root) {
        TreeNode* origin_root = root;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                swap(root->left, root->right);
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            root = root->right;
        }
        return origin_root;
    }
    // using queue, T: O(n) S: O(n)
    TreeNode* invertTreeIterative2(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            swap(node->left, node->right);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};

